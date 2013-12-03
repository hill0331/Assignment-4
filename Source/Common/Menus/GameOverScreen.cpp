//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Game Over screen
//	Modified:		October 30th 2013
//

#include "GameOverScreen.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"
#include "../../Utils/Utils.h"
#include "../../Screen Manager/ScreenManager.h"
#include "SettingsMenu.h"
#include "../Game.h"

#include "../Buttons/GameOverScreenButtonGroup.h"

GameOverScreen::GameOverScreen()
{
	m_BkgTexture = new OpenGLTexture(PAUSE_MENU_BKG_TEXTURE);
	m_GameOverHeaderTexture = new OpenGLTexture(GAME_OVER_SCREEN_HEADER_TEXTURE);

	m_Buttons = new GameOverScreenButtonGroup();	

	//Create the number texture array and create the texture's in the array for each numer
	m_ScoreInfoNumbers = new OpenGLTexture *[GAME_SCORE_INFO_NUMBER_OF_NUMBERS];
	for (int i = 0; i < GAME_SCORE_INFO_NUMBER_OF_NUMBERS; i++)
	{
		m_ScoreInfoNumbers[i] = new OpenGLTexture(GAME_SCORE_INFO_NUMBERS[i]);
	}

	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";
}

GameOverScreen::~GameOverScreen()
{
	if (m_GameOverHeaderTexture != NULL)
	{
		delete m_GameOverHeaderTexture;
		m_GameOverHeaderTexture = NULL;
	}

	if (m_BkgTexture != NULL)
	{
		delete m_BkgTexture;
		m_BkgTexture = NULL;
	}

	if (m_Buttons != NULL)
	{
		delete m_Buttons;
		m_Buttons = NULL;
	}

	if (m_ScoreInfoNumbers != NULL)
	{
		for (int i = 0; i < GAME_SCORE_INFO_NUMBER_OF_NUMBERS; i++)
		{
			delete m_ScoreInfoNumbers[i];
			m_ScoreInfoNumbers[i] = NULL;
		}

		delete[] m_ScoreInfoNumbers;
		m_ScoreInfoNumbers = NULL;
	}
}

void GameOverScreen::update(double delta)
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

void GameOverScreen::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BkgTexture, 0.0f, 0.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_GameOverHeaderTexture, (getWidth() - m_GameOverHeaderTexture->getSourceWidth()) / 2, (getHeight() - m_GameOverHeaderTexture->getSourceHeight()) / 2);

	drawNumber(m_LeftSaves, 750, 405);
	drawNumber(m_RightSaves, 750, 510);
	drawNumber(m_LeftGoalsScored, 1050, 405);
	drawNumber(m_RightGoalsScored, 1050, 510);

	m_Buttons->paint();

	//Fade Effect
	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);
}

const char* GameOverScreen::getName()
{
	return GAME_OVER_SCREEN_NAME;
}

//Screen event method, inherited from the screen class
void GameOverScreen::screenWillAppear()
{
	Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);

	//Get info from game
	m_LeftGoalsScored = game->getLeftPlayerGoals();
	m_RightGoalsScored = game->getRightPlayerGoals();
	m_LeftSaves = game->getLeftPlayerSaves();
	m_RightSaves = game->getRightPlayerSaves();

	//Fade effect
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";	
}

void GameOverScreen::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
	//Handle mouse movement events here
}

void GameOverScreen::mouseLeftClickDownEvent(float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickDownEvent(positionX, positionY);
	}
	//Handle mouse left click down events here
}

void GameOverScreen::mouseRightClickDownEvent(float positionX, float positionY)
{
	//Handle mouse right click down events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickDownEvent(positionX, positionY);
	}
}

void GameOverScreen::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Handle mouse left click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void GameOverScreen::mouseRightClickUpEvent(float positionX, float positionY)
{
	//Handle mouse right click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickUpEvent(positionX, positionY);
	}
}

void GameOverScreen::keyDownEvent(int keyCode)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->keyDownEvent(keyCode);
	}
	//Handle keyboard down events here
}

void GameOverScreen::keyUpEvent(int keyCode)
{
	//Handle keyboard up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->keyUpEvent(keyCode);
	}
}

void GameOverScreen::transitionOut(const char* screenName)
{
	ScreenManager::getInstance()->switchScreen(screenName);
}

void GameOverScreen::buttonPressed(int buttonNumber)
{	
	if (buttonNumber == 0) 
	{
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->reset();

		m_ScreenToTransition = GAME_SCREEN_NAME;
		m_TransitionOut = true;
	}

	if (buttonNumber == 1)
	{
		m_ScreenToTransition = MAIN_MENU_NAME;
		m_TransitionOut = true;
	}
}

void GameOverScreen::drawNumber(int number, float x, float y)
{
	int digitToDraw = number % 10;
	OpenGLTexture *digit = m_ScoreInfoNumbers[digitToDraw];
	OpenGLRenderer::getInstance()->drawTexture(digit, x - (float)(digit->getSourceWidth()), y, (float)(digit->getSourceWidth()), (float)(digit->getSourceHeight()));
	if (number >= 10)
	{
		drawNumber(number / 10, x - (digit->getSourceWidth()) - 2, y);
	}
}