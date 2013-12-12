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
	m_LogoTexture = new OpenGLTexture(SPLASH_SCREEN_LOGO_TEXTURE);

	m_CurrentAlpha = 1;
	m_CurrentAlpha2 = 0;
	m_Transition = false;

	OpenGLRenderer::getInstance()->setBackgroundColor(OpenGLColorBlack());
}

SplashScreen::~SplashScreen()
{
	if (m_LogoTexture != NULL)
	{
		delete m_LogoTexture;
		m_LogoTexture = NULL;
	}
	
}

void SplashScreen::update(double delta)
{
	static float timeElpased; 	

	if (timeElpased > 2.0f && timeElpased < 4.0f)
	{
		if (m_CurrentAlpha > 0)
		{
			m_CurrentAlpha -= 0.5f * delta;
		}
		
	}

	if (timeElpased > 6.0f)
	{
		m_Transition = true;
	}

	if (m_Transition == true)
	{
		if (m_CurrentAlpha < 1)
		{
			m_CurrentAlpha += 0.01f;
		}
		else
		{
			ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
		}
	}

	timeElpased += delta;
}

void SplashScreen::paint()
{

	OpenGLRenderer::getInstance()->drawTexture(m_LogoTexture, 100.0f, 300.0f);

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
	
}

//Mouse Events
void SplashScreen::mouseLeftClickUpEvent(float positionX, float positionY)
{
	
}