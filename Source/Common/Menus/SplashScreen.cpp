//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Splash screen
//	Modified:		October 30th 2013
//

#include "SplashScreen.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"


SplashScreen::SplashScreen()
{
	m_BkgTexture = new OpenGLTexture(SPLASH_SCREEN_BKG_TEXTURE);
	m_SpacePromptTexture = new OpenGLTexture(SPLASH_SCREEN_SPACE_PROMPT_TEXTURE);

	m_CurrentAlpha = 1;
	m_CurrentAlpha2 = 0;
	m_Transition = false;

	m_SpacePromptTexture->setAlpha(m_CurrentAlpha2);
}

SplashScreen::~SplashScreen()
{
	if (m_BkgTexture != NULL)
	{
		delete m_BkgTexture;
		m_BkgTexture = NULL;
	}

	if (m_SpacePromptTexture != NULL)
	{
		delete m_SpacePromptTexture;
		m_SpacePromptTexture = NULL;
	}
}

void SplashScreen::update(double delta)
{
	if (m_CurrentAlpha > 0)
	{
		m_CurrentAlpha -= 0.4f * delta;
	}
	else if (m_CurrentAlpha2 < 1)
	{
		m_CurrentAlpha2 += 0.4f * delta;

		m_SpacePromptTexture->setAlpha(m_CurrentAlpha2);
	}

	if (m_Transition == true)
	{
		if (m_CurrentAlpha < 1)
		{
			m_CurrentAlpha += MENU_TRANSITION_TIME * delta;
		}
		else
		{
			ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
		}
	}
}

void SplashScreen::paint()
{

	OpenGLRenderer::getInstance()->drawTexture(m_BkgTexture, 0.0f, 0.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_SpacePromptTexture,
		((ScreenManager::getInstance()->getScreenWidth() - m_SpacePromptTexture->getSourceWidth()) / 2),
		ScreenManager::getInstance()->getScreenHeight() * 0.9f);

	//Fade Effect
	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);

}

const char* SplashScreen::getName()
{
	return SPLASH_SCREEN_NAME;
}

//Screen event method, inherited from the screen class
void SplashScreen::screenWillAppear()
{
	m_CurrentAlpha = 1;
	m_CurrentAlpha2 = 0;
}

//Key Events
void SplashScreen::keyUpEvent(int keyCode)
{
	if (keyCode == VK_SPACE)
	{
		if (m_CurrentAlpha2 > 0.3)
		{
			m_Transition = true;
		}
	}
}

//Mouse Events
void SplashScreen::mouseLeftClickUpEvent(float positionX, float positionY)
{
	if (m_CurrentAlpha2 > 0.3)
	{
		m_Transition = true;
	}
}