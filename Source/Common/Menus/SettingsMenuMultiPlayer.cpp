//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the MultiPlayer Settings Menu
//	Modified:		October 30th 2013
//

#include "SettingsMenuMultiPlayer.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"
#include "../../Utils/Utils.h"
#include "../../Screen Manager/ScreenManager.h"
#include "../Game.h"

#include "../Buttons/SettingsMenuMultiPlayerButtonGroup.h"

SettingsMenuMultiPlayer::SettingsMenuMultiPlayer()
{
	m_BkgTexture = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE);
	m_ScoreTexture = new OpenGLTexture(SETTINGS_MENU_SCORE_HEADER_TEXTURE);
	m_TimeTexture = new OpenGLTexture(SETTINGS_MENU_TIME_HEADER_TEXTURE);
	m_Player1ControlsTexture = new OpenGLTexture(SETTINGS_MENU_CONTROLS_PLAYER_1_HEADER_TEXTURE);
	m_Player2ControlsTexture = new OpenGLTexture(SETTINGS_MENU_CONTROLS_PLAYER_2_HEADER_TEXTURE);

	m_Buttons = new SettingsMenuMultiPlayerButtonGroup();

	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";
	m_IsPaused = false;
	m_IsMultiPlayer = true;
}

SettingsMenuMultiPlayer::~SettingsMenuMultiPlayer()
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

	if (m_Player1ControlsTexture != NULL)
	{
		delete m_Player1ControlsTexture;
		m_Player1ControlsTexture = NULL;
	}

	if (m_Player2ControlsTexture != NULL)
	{
		delete m_Player2ControlsTexture;
		m_Player2ControlsTexture = NULL;
	}

	if (m_Buttons != NULL)
	{
		delete m_Buttons;
		m_Buttons = NULL;
	}
}

void SettingsMenuMultiPlayer::update(double delta)
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

void SettingsMenuMultiPlayer::paint()
{
	float m_ScreenWidth = ScreenManager::getInstance()->getScreenWidth();
	float m_ScreenHeight = ScreenManager::getInstance()->getScreenHeight();

	OpenGLRenderer::getInstance()->drawTexture(m_BkgTexture, 0.0f, 0.0f);

	OpenGLRenderer::getInstance()->drawTexture(m_ScoreTexture, (m_ScreenWidth - m_ScoreTexture->getSourceWidth()) / 2, 140.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_TimeTexture, (m_ScreenWidth - m_TimeTexture->getSourceWidth()) / 2, 280.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_Player1ControlsTexture, (m_ScreenWidth - m_Player1ControlsTexture->getSourceWidth()) / 2, 422.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_Player2ControlsTexture, (m_ScreenWidth - m_Player2ControlsTexture->getSourceWidth()) / 2, 560.0f);

	m_Buttons->paint();

	//Fade effect
	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);
}

const char* SettingsMenuMultiPlayer::getName()
{
	return SETTINGS_MENU_MULTI_PLAYER_NAME;
}

//Screen event method, inherited from the screen class
void SettingsMenuMultiPlayer::screenWillAppear()
{
	static bool firstView = true;

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

void SettingsMenuMultiPlayer::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
	//Handle mouse movement events here
}

void SettingsMenuMultiPlayer::mouseLeftClickDownEvent(float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickDownEvent(positionX, positionY);
	}
	//Handle mouse left click down events here
}

void SettingsMenuMultiPlayer::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Handle mouse left click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void SettingsMenuMultiPlayer::keyDownEvent(int keyCode)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->keyDownEvent(keyCode);
	}
	//Handle keyboard down events here
}

void SettingsMenuMultiPlayer::keyUpEvent(int keyCode)
{
	//Handle keyboard up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->keyUpEvent(keyCode);
	}
}

void SettingsMenuMultiPlayer::transitionOut(const char* screenName)
{
	ScreenManager::getInstance()->switchScreen(screenName);
}

void SettingsMenuMultiPlayer::buttonPressed(int buttonNumber)
{
	if (buttonNumber == 14)
	{
		if (m_IsPaused == true)
		{
			//Get game screen
			Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

			//Set game settings from menu
			game->setGameSettings(m_IsMultiPlayer, m_ScoreLimit, m_TimeLimit, m_Difficulty, m_Player1Controls, m_Player2Controls);

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
		game->setGameSettings(m_IsMultiPlayer, m_ScoreLimit, m_TimeLimit, m_Difficulty, m_Player1Controls, m_Player2Controls);

		//Reset game
		game->reset();

		m_ScreenToTransition = GAME_SCREEN_NAME;
		m_TransitionOut = true;
	}
}

//Get and set
float SettingsMenuMultiPlayer::getScoreLimit()
{
	return m_ScoreLimit;
}

float SettingsMenuMultiPlayer::getTimeLimit()
{
	return m_TimeLimit;
}

float SettingsMenuMultiPlayer::getPlayer1Controls()
{
	return m_Player1Controls;
}

float SettingsMenuMultiPlayer::getPlayer2Controls()
{
	return m_Player2Controls;
}

void SettingsMenuMultiPlayer::setScoreLimit(float score)
{
	m_ScoreLimit = score;
}

void SettingsMenuMultiPlayer::setTimeLimit(float time)
{
	m_TimeLimit = time;
}

void SettingsMenuMultiPlayer::setPlayer1Controls(float difficulty)
{
	m_Player1Controls = difficulty;
}

void SettingsMenuMultiPlayer::setPlayer2Controls(float controls)
{
	m_Player2Controls = controls;
}

void SettingsMenuMultiPlayer::setIsPaused(bool isPaused)
{
	m_IsPaused = isPaused;
}