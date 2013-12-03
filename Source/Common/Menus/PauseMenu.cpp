#include "PauseMenu.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"
#include "../../Utils/Utils.h"
#include "../../Screen Manager/ScreenManager.h"
#include "SettingsMenu.h"
#include "SettingsMenuMultiPlayer.h"
#include "../Game.h"

#include "../Buttons/PauseMenuButtonGroup.h"

PauseMenu::PauseMenu()
{
	m_BkgTexture = new OpenGLTexture(PAUSE_MENU_BKG_TEXTURE);

	m_Buttons = new PauseMenuButtonGroup();	
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";
}

PauseMenu::~PauseMenu()
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

void PauseMenu::update(double delta)
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

void PauseMenu::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BkgTexture, 0.0f, 0.0f);
	m_Buttons->paint();

	//Fade Effect
	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);
}

const char* PauseMenu::getName()
{
	return PAUSE_MENU_NAME;
}

//Screen event method, inherited from the screen class
void PauseMenu::screenWillAppear()
{
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";	
}

void PauseMenu::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}
	//Handle mouse movement events here
}

void PauseMenu::mouseLeftClickDownEvent(float positionX, float positionY)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickDownEvent(positionX, positionY);
	}
	//Handle mouse left click down events here
}

void PauseMenu::mouseRightClickDownEvent(float positionX, float positionY)
{
	//Handle mouse right click down events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickDownEvent(positionX, positionY);
	}
}

void PauseMenu::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Handle mouse left click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void PauseMenu::mouseRightClickUpEvent(float positionX, float positionY)
{
	//Handle mouse right click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickUpEvent(positionX, positionY);
	}
}

void PauseMenu::keyDownEvent(int keyCode)
{
	if (m_Buttons != NULL)
	{
		m_Buttons->keyDownEvent(keyCode);
	}
	//Handle keyboard down events here
}

void PauseMenu::keyUpEvent(int keyCode)
{
	//Handle keyboard up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->keyUpEvent(keyCode);
	}
}

void PauseMenu::transitionOut(const char* screenName)
{
	ScreenManager::getInstance()->switchScreen(screenName);
}

void PauseMenu::buttonPressed(int buttonNumber)
{
	if (buttonNumber == 0) 
	{
		m_ScreenToTransition = GAME_SCREEN_NAME;
		m_TransitionOut = true;		
	}

	if (buttonNumber == 1) 
	{
		Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
		game->reset();

		m_ScreenToTransition = GAME_SCREEN_NAME;
		m_TransitionOut = true;
	}

	if (buttonNumber == 2) 
	{
		if(m_IsMultiPlayer == false)
		{
			SettingsMenu* settingsMenu = (SettingsMenu*)ScreenManager::getInstance()->getScreenForName(SETTINGS_MENU_NAME);

			bool paused = true;
			settingsMenu->setIsPaused(paused);

			m_ScreenToTransition = SETTINGS_MENU_NAME;
		}
		else
		{
			SettingsMenuMultiPlayer* settingsMenu = (SettingsMenuMultiPlayer*)ScreenManager::getInstance()->getScreenForName(SETTINGS_MENU_MULTI_PLAYER_NAME);

			bool paused = true;
			settingsMenu->setIsPaused(paused);

			m_ScreenToTransition = SETTINGS_MENU_MULTI_PLAYER_NAME;
		}

		m_TransitionOut = true;
	}

	if (buttonNumber == 3)
	{
		m_ScreenToTransition = MAIN_MENU_NAME;
		m_TransitionOut = true;
	}
}

void PauseMenu::setIsMultiPlayer(bool isMultiPlayer)
{
	m_IsMultiPlayer = isMultiPlayer;
}