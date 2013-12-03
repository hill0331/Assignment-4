//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Main Menu Screen Code
//	Modified:		October 30th 2013
//

#include "MainMenu.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"

#include "Buttons/MainMenuButtonGroup.h"

MainMenu::MainMenu()
{
	m_BkgTexture = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE);

	m_Buttons = new MainMenuButtonGroup();	
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";
}

MainMenu::~MainMenu()
{
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
}

void MainMenu::update(double delta)
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

void MainMenu::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BkgTexture, 0.0f, 0.0f);
	m_Buttons->paint();

	//Fade Effect
	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);
}

const char* MainMenu::getName()
{
	return MAIN_MENU_SCREEN_NAME;
}

//Screen event method, inherited from the screen class
void MainMenu::screenWillAppear()
{
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";	
}

void MainMenu::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
	//Handle mouse movement events here
}

void MainMenu::mouseLeftClickDownEvent(float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickDownEvent(positionX, positionY);
	}
	//Handle mouse left click down events here
}

void MainMenu::mouseRightClickDownEvent(float positionX, float positionY)
{
	//Handle mouse right click down events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickDownEvent(positionX, positionY);
	}
}

void MainMenu::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Handle mouse left click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void MainMenu::mouseRightClickUpEvent(float positionX, float positionY)
{
	//Handle mouse right click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickUpEvent(positionX, positionY);
	}
}

void MainMenu::keyDownEvent(int keyCode)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->keyDownEvent(keyCode);
	}
	//Handle keyboard down events here
}

void MainMenu::keyUpEvent(int keyCode)
{
	//Handle keyboard up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->keyUpEvent(keyCode);
	}
}

void MainMenu::transitionOut(const char* screenName)
{
	ScreenManager::getInstance()->switchScreen(screenName);
}

void MainMenu::buttonPressed(int buttonNumber)
{
	if (buttonNumber == 0) 
	{
		m_ScreenToTransition = SETTINGS_MENU_SCREEN_NAME;
		m_TransitionOut = true;		
	}

	if (buttonNumber == 1) 
	{
		
	}

	if (buttonNumber == 2) 
	{
		m_ScreenToTransition = CREDITS_SCREEN_NAME;
		m_TransitionOut = true;
	}

	if (buttonNumber == 3) //Quit
	{
		exit(0);
	}
}