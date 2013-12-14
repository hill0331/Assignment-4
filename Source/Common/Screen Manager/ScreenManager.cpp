//
//  ScreenManager.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
// Modified by Dan Lingman on 2013-11-09
// Added SaveMenu and LoadMenu Screens
//
#include "ScreenManager.h"
#include "Screen.h"
#include "../OpenGL/OpenGL.h"
#include "../Menus/MainMenu.h"
#include "../Menus/SplashScreen.h"
#include "../Menus/FileMenu.h"
#include "../Menus/GameOverScreen.h"
#include "../Menus/HighScoresScreen.h"
#include "../Menus/SettingsMenu.h"
#include "../Menus/VictoryScreen.h"
#include <time.h>


ScreenManager* ScreenManager::s_Instance = NULL;
ScreenManager* ScreenManager::getInstance()
{
	if(s_Instance == NULL)
	{
		s_Instance = new ScreenManager();
	}
	
	return s_Instance;
}

void ScreenManager::cleanupInstance()
{
	if(s_Instance != NULL)
	{
		delete s_Instance;
		s_Instance = NULL;
	}
}

ScreenManager::ScreenManager()
{
    //Seed the rand() function
    srand((unsigned int)(time(NULL)));
    
    //Initialize member variables
	m_CurrentScreen = NULL;
	m_ScreensLoaded = false;
}

ScreenManager::~ScreenManager()
{
	//delete all of the screens in the manager
	for(unsigned int i = 0; i < m_Screens.size(); i++)
	{
		delete m_Screens.at(i);
	}
	m_Screens.clear();
    
    //Cleanup the texture instance
    OpenGLTextureCache::cleanupInstance();
}

void ScreenManager::loadScreens()
{
	//Create the Game screens
	//addScreen(new SplashScreen());
    addScreen(new MainMenu());	
	addScreen(new FileMenu());
	addScreen(new HighScoresScreen());
	addScreen(new SettingsMenu());
	addScreen(new GameOverScreen());
	addScreen(new VictoryScreen());
}

void ScreenManager::setScreenSize(float aWidth, float aHeight)
{
    m_ScreenWidth = aWidth;
    m_ScreenHeight = aHeight;
    
    if(m_ScreensLoaded == false)
    {
        loadScreens();
        m_ScreensLoaded = true;
    }
}

float ScreenManager::getScreenWidth()
{
    return m_ScreenWidth;
}

float ScreenManager::getScreenHeight()
{
    return m_ScreenHeight;
}

void ScreenManager::update(double delta)
{
	if(m_CurrentScreen != NULL)
	{
		m_CurrentScreen->update(delta);
	}
}

void ScreenManager::paint()
{
	if(m_CurrentScreen != NULL)
	{
		m_CurrentScreen->paint();
	}
}

void ScreenManager::addScreen(Screen* aScreen)
{
    if(aScreen != NULL)
    {
        //If this is the first screen, make it the current screen
        if(m_Screens.size() == 0)
        {
            m_CurrentScreen = aScreen;
            m_CurrentScreen->screenWillAppear();
            InputManager::getInstance()->registerListener(m_CurrentScreen);
        }
        
        //
        m_Screens.push_back(aScreen);
    }
}

void ScreenManager::removeScreen(const char* aName)
{
	//find the screen and return it
	for (unsigned int i = 0; i < m_Screens.size(); i++)
	{
		if (strcmp(m_Screens.at(i)->getName(), aName) == 0)
		{
			delete m_Screens.at(i);
			m_Screens.erase(m_Screens.begin() + i);
		}
	}
	return;
}

void ScreenManager::switchScreen(Screen* aScreen)
{
	if(aScreen != NULL)
	{
		switchScreen(aScreen->getName());
	}
}

void ScreenManager::switchScreen(const char* aName)
{
	//look for then screen with the name and make it the current
	for(unsigned int i = 0; i < m_Screens.size(); i++)
	{
		if(strcmp(m_Screens[i]->getName(), aName) == 0)
		{
            InputManager::getInstance()->unregisterListener();
            m_CurrentScreen->screenWillDisappear();
            m_CurrentScreen = m_Screens.at(i);
            m_CurrentScreen->screenWillAppear();
            InputManager::getInstance()->registerListener(m_CurrentScreen);
            return;
		}
	}
}

Screen* ScreenManager::getCurrentScreen()
{
	return m_CurrentScreen;
}

Screen* ScreenManager::getScreenForName(const char* aName)
{
	//find the screen and return it
	for(unsigned int i = 0; i < m_Screens.size(); i++)
	{
		if(strcmp(m_Screens.at(i)->getName(), aName) == 0)
		{
			return m_Screens.at(i);
		}
	}
    return NULL;
}
