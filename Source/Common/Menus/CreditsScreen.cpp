//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Credits screen
//	Modified:		October 30th 2013
//

#include "CreditsScreen.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"
#include "../../Utils/Utils.h"
#include "../../Screen Manager/ScreenManager.h"

CreditsScreen::CreditsScreen()
{
	m_BkgTexture = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE);
	m_TextBkgTexture = new OpenGLTexture(CREDITS_SCREEN_BKG_TEXTURE);
	m_TextTexture = new OpenGLTexture(CREDITS_SCREEN_SCROLLING_TEXTURE);

	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";

	m_TextY = getHeight();
}

CreditsScreen::~CreditsScreen()
{
	if (m_BkgTexture != NULL)
	{
		delete m_BkgTexture;
		m_BkgTexture = NULL;
	}

	if (m_TextBkgTexture != NULL)
	{
		delete m_TextBkgTexture;
		m_TextBkgTexture = NULL;
	}

	if (m_TextTexture != NULL)
	{
		delete m_TextTexture;
		m_TextTexture = NULL;
	}
}

void CreditsScreen::update(double delta)
{
	if (m_TextY > -1000.0f)
	{
		m_TextY -= 100 * delta;
	}
	else
	{
		m_TextY = getHeight();
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

void CreditsScreen::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BkgTexture, 0.0f, 0.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_TextBkgTexture, (getWidth() - m_TextBkgTexture->getSourceWidth()) /2, 0.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_TextTexture, (getWidth() - m_TextTexture->getSourceWidth()) / 2, m_TextY);

	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);
}

const char* CreditsScreen::getName()
{
	return CREDITS_SCREEN_NAME;
}

//Screen event method, inherited from the screen class
void CreditsScreen::screenWillAppear()
{
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";
	m_TextY = getHeight();
}

//Key Events
void CreditsScreen::keyUpEvent(int keyCode)
{
	if (keyCode == VK_ESCAPE)
	{
		m_ScreenToTransition = MAIN_MENU_NAME;
		m_TransitionOut = true;
	}
}

//Mouse Events
void CreditsScreen::mouseLeftClickUpEvent(float positionX, float positionY)
{

	ScreenManager::getInstance()->switchScreen(MAIN_MENU_NAME);

}

void CreditsScreen::transitionOut(const char* screenName)
{
	ScreenManager::getInstance()->switchScreen(screenName);
}