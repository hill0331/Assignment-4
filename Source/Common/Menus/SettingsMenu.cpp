//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		High Scores Screen Code
//	Modified:		December 12th 2013
//

#include "SettingsMenu.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include <algorithm>
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIFont.h"
#include <sstream>

//File IO
#include <stdlib.h>
#include <fstream>
#include "../Libraries/jsoncpp/json.h"

#include "Buttons/SettingsMenuButtonGroup.h"

SettingsMenu::SettingsMenu()
{
	m_BkgTextureCount = 2;

	m_BkgTextureList = new OpenGLTexture *[m_BkgTextureCount];

	m_BkgTextureList[0] = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE_0);
	m_BkgTextureList[1] = new OpenGLTexture(MAIN_MENU_BKG_TEXTURE_1);

	m_OverlayTexture = new OpenGLTexture(GAME_MAP_OVERLAY_TEXTURE);

	m_TitleTex = new OpenGLTexture(SETTINGS_MENU_TITLE_TEXTURE);
	m_Difficulty = NORMAL;

	m_Buttons = new SettingsMenuButtonGroup();
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";

	m_BkgTexturePosition = 0.0f;
	m_CurrentBkgTexture = 0;
	m_BkgAlpha = 0;
}

SettingsMenu::~SettingsMenu()
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

void SettingsMenu::update(double delta)
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

void SettingsMenu::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BkgTextureList[m_CurrentBkgTexture], m_BkgTexturePosition, 0.0f);

	OpenGLRenderer::getInstance()->drawTexture(m_OverlayTexture, 0.0f, 0.0f);

	//Fade Effect bkg
	OpenGLColor fillColor0 = OpenGLColor(0, 0, 0, m_BkgAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor0);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);

	OpenGLRenderer::getInstance()->drawTexture(m_TitleTex, (getWidth() - m_TitleTex->getSourceWidth()) / 2, getHeight() *0.15f);


	m_Buttons->paint();

	//Fade Effect
	OpenGLColor fillColor = OpenGLColor(0, 0, 0, m_CurrentAlpha);
	OpenGLRenderer::getInstance()->setForegroundColor(fillColor);
	OpenGLRenderer::getInstance()->drawRectangle(0.0f, 0.0f, getWidth(), getHeight(), true);
}

//File loading/saving
void SettingsMenu::loadSettings()
{
	//If the level name isn't NULL load the level from the filesystem,
	//if it is NULL load an empty level with just ground tiles

	Json::Value root;
	Json::Reader reader;
	std::ifstream in;

	in.open("Settings.json");

	bool success = reader.parse(in, root, false);

	if (success == true)
	{	
		const Json::Value settings = root["settings"];		

		//Cycle through all the tiles and create them
		for (int i = 0; i < settings.size(); i++)
		{
			//Deterime setting
			int setting = settings[i].get("difficulty", NULL).asInt();
			m_Difficulty = setting;
		}
	}

	in.close();
}

void SettingsMenu::saveSettings()
{
	Json::Value root;

	Json::Value settings;
	Json::Value difficulty;
	
	//Copy the settings data into the buffer	
	difficulty["difficulty"] = m_Difficulty;
	settings.append(difficulty);	

	root["settings"] = settings;

	std::ofstream out;
	out.open("Settings.json");
	out << root;
	out.close();
}


const char* SettingsMenu::getName()
{
	return SETTINGS_MENU_SCREEN_NAME;
}

//Screen event method, inherited from the screen class
void SettingsMenu::screenWillAppear()
{
	m_CurrentAlpha = 1;
	m_TransitionOut = false;
	m_ScreenToTransition = "";	
	loadSettings();	
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

void SettingsMenu::mouseRightClickDownEvent(float positionX, float positionY)
{
	//Handle mouse right click down events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickDownEvent(positionX, positionY);
	}
}

void SettingsMenu::mouseLeftClickUpEvent(float positionX, float positionY)
{
	//Handle mouse left click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void SettingsMenu::mouseRightClickUpEvent(float positionX, float positionY)
{
	//Handle mouse right click up events here
	if (m_Buttons != NULL)
	{
		m_Buttons->mouseRightClickUpEvent(positionX, positionY);
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
	if (buttonNumber == 0)
	{
		m_Difficulty = 0;
	}
	else if (buttonNumber == 1)
	{
		m_Difficulty = 1;
	}
	else if (buttonNumber == 2)
	{
		m_Difficulty = 2;
	}
	else if (buttonNumber == 3)
	{
		saveSettings();

		m_ScreenToTransition = MAIN_MENU_SCREEN_NAME;
		m_TransitionOut = true;
	}	
}