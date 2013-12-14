//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Main Menu Screen Code
//	Modified:		October 30th 2013
//

#include "GameOverScreen.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"

#include "../Game/Game.h"
#include "HighScoresScreen.h"

#include "Buttons/GameOverScreenButtonGroup.h"

GameOverScreen::GameOverScreen()
{
	m_BkgTextureCount = 2;

	m_BkgTextureList = new OpenGLTexture *[m_BkgTextureCount];

	m_BkgTextureList[0] = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE_0);
	m_BkgTextureList[1] = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE_1);

	m_OverlayTexture = new OpenGLTexture(GAME_MAP_OVERLAY_TEXTURE);

	m_TitleTex = new OpenGLTexture(GAME_OVER_SCREEN_TITLE_TEXTURE);

	m_Buttons = new GameOverScreenButtonGroup();
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";

	m_BkgTexturePosition = 0.0f;
	m_CurrentBkgTexture = 0;
	m_BkgAlpha = 0;
}

GameOverScreen::~GameOverScreen()
{
	if (m_OverlayTexture != NULL)
	{
		delete m_OverlayTexture;
		m_OverlayTexture = NULL;
	}

	if (m_TitleTex != NULL)
	{
		delete m_TitleTex;
		m_TitleTex = NULL;
	}

	for (int i = 0; i < m_BkgTextureCount; i++)
	{
		if (m_BkgTextureList[i] != NULL)
		{
			delete m_BkgTextureList[i];
			m_BkgTextureList[i] = NULL;
		}
	}

	if (m_Buttons != NULL)
	{
		delete m_Buttons;
		m_Buttons = NULL;
	}
}

void GameOverScreen::update(double delta)
{

	m_Buttons->update(delta);
	//Alpha transition for background textures
	if (abs(m_BkgTexturePosition) <= m_BkgTextureList[m_CurrentBkgTexture]->getSourceWidth() * 0.05)
	{
		m_BkgAlpha = 1 - abs(m_BkgTexturePosition) / (m_BkgTextureList[m_CurrentBkgTexture]->getSourceWidth() * 0.05);
	}
	else if (abs(m_BkgTexturePosition) >= (m_BkgTextureList[m_CurrentBkgTexture]->getSourceWidth() - ScreenManager::getInstance()->getScreenWidth()) * 0.85)
	{
		float x = abs(m_BkgTexturePosition) / (m_BkgTextureList[m_CurrentBkgTexture]->getSourceWidth() - ScreenManager::getInstance()->getScreenWidth());
		m_BkgAlpha = (x - 0.85) / 0.15;

	}

	//Switch background textures
	if (abs(m_BkgTexturePosition) > m_BkgTextureList[m_CurrentBkgTexture]->getSourceWidth() - ScreenManager::getInstance()->getScreenWidth())
	{
		if (m_CurrentBkgTexture < m_BkgTextureCount - 1)
		{
			m_CurrentBkgTexture++;
			m_BkgTexturePosition = 0.0f;
		}
		else
		{
			m_CurrentBkgTexture = 0;
			m_BkgTexturePosition = 0.0f;
		}
	}
	else
	{
		//Scroll Background
		m_BkgTexturePosition -= (BACKGROUND_SCROLL_SPEED * delta);
	}

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
	OpenGLRenderer::getInstance()->drawTexture(m_BkgTextureList[m_CurrentBkgTexture], m_BkgTexturePosition, 0.0f);	

	OpenGLRenderer::getInstance()->drawTexture(m_OverlayTexture, 0.0f, 0.0f);	

	//Fade Effect bkg
	OpenGLColor fillColor0 = OpenGLColor(0, 0, 0, m_BkgAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor0);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);

	OpenGLRenderer::getInstance()->drawTexture(m_TitleTex, (getWidth() - m_TitleTex->getSourceWidth()) / 2, getHeight() *0.3f);

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
	Game * gameScreen = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
	HighScoresScreen * highScoresScreen = (HighScoresScreen*)ScreenManager::getInstance()->getScreenForName(HIGH_SCORES_SCREEN_NAME);

	highScoresScreen->addScore(gameScreen->getPlayerScore());

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
		m_ScreenToTransition = MAIN_MENU_SCREEN_NAME;
		m_TransitionOut = true;
	}
	else if (buttonNumber == 1)
	{
		m_ScreenToTransition = HIGH_SCORES_SCREEN_NAME;
		m_TransitionOut = true;
	}
	else if (buttonNumber == 2)
	{
		exit(0);
	}
}