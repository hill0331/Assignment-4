//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Settings Screen code for the single player menu
//	Modified:		October 30th 2013
//

#include "SettingsMenu.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"
#include "../../Utils/Utils.h"
#include "../../Screen Manager/ScreenManager.h"
#include "../Game.h"

#include "../Buttons/SettingsMenuButtonGroup.h"

SettingsMenu::SettingsMenu()
{
	m_BkgTexture = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE);
	m_ScoreTexture = new OpenGLTexture(SETTINGS_MENU_SCORE_HEADER_TEXTURE);
	m_TimeTexture = new OpenGLTexture(SETTINGS_MENU_TIME_HEADER_TEXTURE);
	m_DifficultyTexture = new OpenGLTexture(SETTINGS_MENU_DIFFICULTY_HEADER_TEXTURE);
	m_ControlsTexture = new OpenGLTexture(SETTINGS_MENU_CONTROLS_HEADER_TEXTURE);

	m_Buttons = new SettingsMenuButtonGroup();

	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";
	m_IsPaused = false;
	m_IsMultiPlayer = false;
}

SettingsMenu::~SettingsMenu()
{
	if (m_BkgTexture != NULL)
	{
		delete m_BkgTexture;
		m_BkgTexture = NULL;
	}

	if (m_ScoreTexture != NULL)
	{
		delete m_ScoreTexture;
		m_ScoreTexture = NULL;
	}

	if (m_TimeTexture != NULL)
	{
		delete m_TimeTexture;
		m_TimeTexture = NULL;
	}

	if (m_DifficultyTexture != NULL)
	{
		delete m_DifficultyTexture;
		m_DifficultyTexture = NULL;
	}

	if (m_ControlsTexture != NULL)
	{
		delete m_ControlsTexture;
		m_ControlsTexture = NULL;
	}

	if (m_Buttons != NULL)
	{
		delete m_Buttons;
		m_Buttons = NULL;
	}
}

void SettingsMenu::update(double delta)
{
	m_Buttons->update(delta);

	if (m_TransitionOut == false && m_CurrentAlpha > 0)
	{
		m_CurrentAlpha -= MENU_TRANSITION_TIME * delta;
	}

	if (m_TransitionOut == true)
	{
		if (m_CurrentAlpha < 1)
		{
			m_CurrentAlpha += MENU_TRANSITION_TIME * delta;
		}
		else
		{
			transitionOut((m_ScreenToTransition.c_str()));
		}
	}
}

void SettingsMenu::paint()
{
	float m_ScreenWidth = ScreenManager::getInstance()->getScreenWidth();
	float m_ScreenHeight = ScreenManager::getInstance()->getScreenHeight();

	OpenGLRenderer::getInstance()->drawTexture(m_BkgTexture, 0.0f, 0.0f);

	OpenGLRenderer::getInstance()->drawTexture(m_ScoreTexture, (m_ScreenWidth - m_ScoreTexture->getSourceWidth()) / 2, 135.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_TimeTexture, (m_ScreenWidth - m_TimeTexture->getSourceWidth()) / 2, 280.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_DifficultyTexture, (m_ScreenWidth - m_DifficultyTexture->getSourceWidth()) / 2, 422.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_ControlsTexture, (m_ScreenWidth - m_DifficultyTexture->getSourceWidth()) / 2, 550.0f);

	m_Buttons->paint();

	//Fade effect
	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);
}

const char* SettingsMenu::getName()
{
	return SETTINGS_MENU_NAME;
}

//Screen event method, inherited from the screen class
void SettingsMenu::screenWillAppear()
{
	static bool firstView  = true;

	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";
	m_Buttons->initializeGroup(m_IsPaused);

	if (firstView == true)
	{
		m_Buttons->setDefaultValues();
		firstView = false;
	}
}

void SettingsMenu::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
	//Handle mouse movement events here
}

void SettingsMenu::mouseLeftClickDownEvent(float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickDownEvent(positionX, positionY);
	}
	//Handle mouse left click down events here
}

void SettingsMenu::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Handle mouse left click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void SettingsMenu::keyDownEvent(int keyCode)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->keyDownEvent(keyCode);
	}
	//Handle keyboard down events here
}

void SettingsMenu::keyUpEvent(int keyCode)
{
	//Handle keyboard up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->keyUpEvent(keyCode);
	}
}

void SettingsMenu::transitionOut(const char* screenName)
{
	ScreenManager::getInstance()->switchScreen(screenName);
}

void SettingsMenu::buttonPressed(int buttonNumber)
{
	if (buttonNumber == 14)
	{
		if (m_IsPaused == true)
		{
			//Get game screen
			Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

			//Set game settings from menu
			game->setGameSettings(m_IsMultiPlayer, m_ScoreLimit, m_TimeLimit, m_Difficulty, m_PlayerControls, 0);

			m_ScreenToTransition = PAUSE_MENU_NAME;
			m_IsPaused = false;
		}
		else
		{
			m_ScreenToTransition = MAIN_MENU_NAME;
		}

		m_TransitionOut = true;
	}

	if (buttonNumber == 15)
	{
		//Get game screen
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

		//Set game settings from menu
		game->setGameSettings(m_IsMultiPlayer, m_ScoreLimit, m_TimeLimit, m_Difficulty, m_PlayerControls, 0);

		//Reset game
		game->reset();

		m_ScreenToTransition = GAME_SCREEN_NAME;
		m_TransitionOut = true;
	}
}

//Get and set
float SettingsMenu::getScoreLimit()
{
	return m_ScoreLimit;
}
float SettingsMenu::getTimeLimit()
{
	return m_TimeLimit;
}
float SettingsMenu::getDifficulty()
{
	return m_Difficulty;
}
float SettingsMenu::getPlayer1Controls()
{
	return m_PlayerControls;
}

void SettingsMenu::setScoreLimit(float score)
{
	m_ScoreLimit = score;
}
void SettingsMenu::setTimeLimit(float time)
{
	m_TimeLimit = time;
}
void SettingsMenu::setDifficulty(float difficulty)
{
	m_Difficulty = difficulty;
}
void SettingsMenu::setPlayer1Controls(float controls)
{
	m_PlayerControls = controls;
}
void SettingsMenu::setIsPaused(bool isPaused)
{
	m_IsPaused = isPaused;
}