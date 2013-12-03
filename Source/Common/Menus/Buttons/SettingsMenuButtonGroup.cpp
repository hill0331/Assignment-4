//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the single player settings menu buttons
//	Modified:		October 30th 2013
//

#include "SettingsMenuButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "GameButton.h"
#include "../Menus/SettingsMenu.h"

SettingsMenuButtonGroup::SettingsMenuButtonGroup()
{
	float scorePadding = 50;
	float scoreWidth = 100;
	float scoreInitialX = (ScreenManager::getInstance()->getScreenWidth() - (scoreWidth * 4 + scorePadding * 3)) / 2;
	float scoreY = 200;

	float timePadding = 50;
	float timeWidth = 100;
	float timeInitialX = (ScreenManager::getInstance()->getScreenWidth() - (timeWidth * 4 + timePadding * 3)) / 2;
	float timeY = 340;

	float diffPadding = 50;
	float diffWidth = 200;
	float diffInitialX = (ScreenManager::getInstance()->getScreenWidth() - (diffWidth * 3 + diffPadding * 2)) / 2;
	float diffY = 480;

	float controlPadding = 50;
	float controlWidth = 263;
	float controlInitialX = (ScreenManager::getInstance()->getScreenWidth() - (controlWidth * 3 + controlPadding *2)) / 2;
	float controlY = 620;

	float backPlayWidth = 200;
	float backPlayY = 800;
	float backX = (float)(ScreenManager::getInstance()->getScreenWidth() * 0.05);

	m_ScoreButton3 = new GameButton(scoreInitialX, scoreY, 100.0f, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/score3_0",
		"/UI/SettingsMenu/buttons/score3_1",
		"/UI/SettingsMenu/buttons/score3_2",
		"/UI/SettingsMenu/buttons/score3_3",
		"/UI/SettingsMenu/buttons/score3_0");

	m_ScoreButton5 = new GameButton(scoreInitialX + (scoreWidth + scorePadding), scoreY, scoreWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/score5_0",
		"/UI/SettingsMenu/buttons/score5_1",
		"/UI/SettingsMenu/buttons/score5_2",
		"/UI/SettingsMenu/buttons/score5_3",
		"/UI/SettingsMenu/buttons/score5_0");

	m_ScoreButton10 = new GameButton(scoreInitialX + (scoreWidth + scorePadding) * 2, scoreY, scoreWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/score10_0",
		"/UI/SettingsMenu/buttons/score10_1",
		"/UI/SettingsMenu/buttons/score10_2",
		"/UI/SettingsMenu/buttons/score10_3",
		"/UI/SettingsMenu/buttons/score10_0");

	m_ScoreButtonInf = new GameButton(scoreInitialX + (scoreWidth + scorePadding) * 3, scoreY, scoreWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/infinite_0",
		"/UI/SettingsMenu/buttons/infinite_1",
		"/UI/SettingsMenu/buttons/infinite_2",
		"/UI/SettingsMenu/buttons/infinite_3",
		"/UI/SettingsMenu/buttons/infinite_0");

	m_TimeButton1 = new GameButton(timeInitialX, timeY, timeWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/time1_0",
		"/UI/SettingsMenu/buttons/time1_1",
		"/UI/SettingsMenu/buttons/time1_2",
		"/UI/SettingsMenu/buttons/time1_3",
		"/UI/SettingsMenu/buttons/time1_0");

	m_TimeButton2 = new GameButton(timeInitialX + (timeWidth + timePadding), timeY, timeWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/time2_0",
		"/UI/SettingsMenu/buttons/time2_1",
		"/UI/SettingsMenu/buttons/time2_2",
		"/UI/SettingsMenu/buttons/time2_3",
		"/UI/SettingsMenu/buttons/time2_0");

	m_TimeButton5 = new GameButton(timeInitialX + (timeWidth + timePadding) * 2, timeY, timeWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/time5_0",
		"/UI/SettingsMenu/buttons/time5_1",
		"/UI/SettingsMenu/buttons/time5_2",
		"/UI/SettingsMenu/buttons/time5_3",
		"/UI/SettingsMenu/buttons/time5_0");

	m_TimeButtonInf = new GameButton(timeInitialX + (timeWidth + timePadding) * 3, timeY, timeWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/infinite_0",
		"/UI/SettingsMenu/buttons/infinite_1",
		"/UI/SettingsMenu/buttons/infinite_2",
		"/UI/SettingsMenu/buttons/infinite_3",
		"/UI/SettingsMenu/buttons/infinite_0");

	m_DiffButtonEasy = new GameButton(diffInitialX, diffY, diffWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/easy0",
		"/UI/SettingsMenu/buttons/easy1",
		"/UI/SettingsMenu/buttons/easy2",
		"/UI/SettingsMenu/buttons/easy3",
		"/UI/SettingsMenu/buttons/easy0");

	m_DiffButtonNormal = new GameButton(diffInitialX + (diffWidth + diffPadding), diffY, diffWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/normal0",
		"/UI/SettingsMenu/buttons/normal1",
		"/UI/SettingsMenu/buttons/normal2",
		"/UI/SettingsMenu/buttons/normal3",
		"/UI/SettingsMenu/buttons/normal0");

	m_DiffButtonHard = new GameButton(diffInitialX + (diffWidth + diffPadding) * 2, diffY, diffWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/hard0",
		"/UI/SettingsMenu/buttons/hard1",
		"/UI/SettingsMenu/buttons/hard2",
		"/UI/SettingsMenu/buttons/hard3",
		"/UI/SettingsMenu/buttons/hard0");

	m_ControlButtonKeyboardArrows = new GameButton(controlInitialX, controlY, controlWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/keyboardArrows_0",
		"/UI/SettingsMenu/buttons/keyboardArrows_1",
		"/UI/SettingsMenu/buttons/keyboardArrows_2",
		"/UI/SettingsMenu/buttons/keyboardArrows_3",
		"/UI/SettingsMenu/buttons/keyboardArrows_0");

	m_ControlButtonKeyboardWASD = new GameButton(controlInitialX + (controlWidth + controlPadding), controlY, controlWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/keyboardWASD_0",
		"/UI/SettingsMenu/buttons/keyboardWASD_1",
		"/UI/SettingsMenu/buttons/keyboardWASD_2",
		"/UI/SettingsMenu/buttons/keyboardWASD_3",
		"/UI/SettingsMenu/buttons/keyboardWASD_0");

	m_ControlButtonMouse = new GameButton(controlInitialX + (controlWidth + controlPadding) * 2, controlY, controlWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/mouse0",
		"/UI/SettingsMenu/buttons/mouse1",
		"/UI/SettingsMenu/buttons/mouse2",
		"/UI/SettingsMenu/buttons/mouse3",
		"/UI/SettingsMenu/buttons/mouse0");

	m_BackButton = new GameButton(backX, backPlayY, backPlayWidth, 75.0f, ENABLED_BUTTON,
		"/UI/SettingsMenu/buttons/back0",
		"/UI/SettingsMenu/buttons/back1",
		"/UI/SettingsMenu/buttons/back2",
		"/UI/SettingsMenu/buttons/back3",
		"/UI/SettingsMenu/buttons/back0");

}

SettingsMenuButtonGroup::~SettingsMenuButtonGroup()
{

}

void SettingsMenuButtonGroup::initializeGroup(bool isPaused)
{
	//Set value in button group
	m_IsPaused = isPaused;

	//Clear vector before adding buttons
	m_Buttons.clear();	

	addGameButton(m_ScoreButton3);	//0
	addGameButton(m_ScoreButton5);
	addGameButton(m_ScoreButton10);
	addGameButton(m_ScoreButtonInf);
	addGameButton(m_TimeButton1);
	addGameButton(m_TimeButton2);
	addGameButton(m_TimeButton5);
	addGameButton(m_TimeButtonInf);
	addGameButton(m_DiffButtonEasy);
	addGameButton(m_DiffButtonNormal);
	addGameButton(m_DiffButtonHard);
	addGameButton(m_ControlButtonKeyboardArrows);
	addGameButton(m_ControlButtonKeyboardWASD);
	addGameButton(m_ControlButtonMouse);
	addGameButton(m_BackButton);  //14

	//If we are not paused, draw the play button
	if (isPaused == false)
	{
		float backPlayWidth = 200;
		float backPlayY = 800;
		float playX = (float)(ScreenManager::getInstance()->getScreenWidth() * 0.95) - backPlayWidth;

		GameButton * m_PlayButton = new GameButton(playX, backPlayY, backPlayWidth, 75.0f, ENABLED_BUTTON,
			"/UI/SettingsMenu/buttons/play0",
			"/UI/SettingsMenu/buttons/play1",
			"/UI/SettingsMenu/buttons/play2",
			"/UI/SettingsMenu/buttons/play3",
			"/UI/SettingsMenu/buttons/play0");

		addGameButton(m_PlayButton); //15
	}
}

void SettingsMenuButtonGroup::handleButtonTrigger(int buttonNumber)
{
	// YOUR CODE TO DEAL WITH BUTTON CLICKS GOES HERE

	SettingsMenu* settingsMenu = (SettingsMenu*)ScreenManager::getInstance()->getScreenForName(SETTINGS_MENU_NAME);

	if (buttonNumber == 0)
	{
		settingsMenu->setScoreLimit(3);

		for (int i = 0; i < 4; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}

		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 1)
	{
		settingsMenu->setScoreLimit(5);
		for (int i = 0; i < 4; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 2)
	{
		settingsMenu->setScoreLimit(10);
		for (int i = 0; i < 4; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 3)
	{
		settingsMenu->setScoreLimit(0);
		for (int i = 0; i < 4; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 4)
	{
		settingsMenu->setTimeLimit(1);
		for (int i = 4; i < 8; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 5)
	{
		settingsMenu->setTimeLimit(2);
		for (int i = 4; i < 8; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 6)
	{
		settingsMenu->setTimeLimit(5);
		for (int i = 4; i < 8; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 7)
	{
		settingsMenu->setTimeLimit(0);
		for (int i = 4; i < 8; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 8)
	{
		settingsMenu->setDifficulty(EASY);
		for (int i = 8; i < 11; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 9)
	{
		settingsMenu->setDifficulty(NORMAL);
		for (int i = 8; i < 11; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 10)
	{
		settingsMenu->setDifficulty(HARD);
		for (int i = 8; i < 11; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 11)
	{
		settingsMenu->setPlayer1Controls(KEYBOARD_ARROWS);
		for (int i = 11; i < 14; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 12)
	{
		settingsMenu->setPlayer1Controls(KEYBOARD_WASD);
		for (int i = 11; i < 14; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 13)
	{
		settingsMenu->setPlayer1Controls(MOUSE);
		for (int i = 11; i < 14; i++)
		{
			m_Buttons.at(i)->setState(ENABLED_BUTTON);
		}
		m_Buttons[buttonNumber]->setState(DISABLED_BUTTON);
	}

	else if (buttonNumber == 14)
	{
		settingsMenu->buttonPressed(buttonNumber);
	}

	else if (buttonNumber == 15)
	{
		settingsMenu->buttonPressed(buttonNumber);
	}
}

void SettingsMenuButtonGroup::setDefaultValues()
{
	SettingsMenu* settingsMenu = (SettingsMenu*)ScreenManager::getInstance()->getScreenForName(SETTINGS_MENU_NAME);

	settingsMenu->setScoreLimit(3);
	m_Buttons[0]->setState(DISABLED_BUTTON);

	settingsMenu->setTimeLimit(1);
	m_Buttons[4]->setState(DISABLED_BUTTON);

	settingsMenu->setDifficulty(EASY);
	m_Buttons[8]->setState(DISABLED_BUTTON);

	settingsMenu->setPlayer1Controls(KEYBOARD_ARROWS);
	m_Buttons[11]->setState(DISABLED_BUTTON);

}

