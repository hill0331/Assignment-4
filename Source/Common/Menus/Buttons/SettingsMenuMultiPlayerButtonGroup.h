//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the MultiPlayer Settings menu buttons
//	Modified:		October 30th 2013
//

#ifndef SETTINGS_MENU_BUTTON_GROUP
#define SETTINGS_MENU_BUTTON_GROUP

#include <iostream>
#include "ButtonGroup.h"

class GameButton;

class SettingsMenuMultiPlayerButtonGroup : public ButtonGroup
{

public:
	SettingsMenuMultiPlayerButtonGroup();
	virtual ~SettingsMenuMultiPlayerButtonGroup();
	void handleButtonTrigger(int buttonNumber);
	void initializeGroup(bool isPaused);
	void setDefaultValues();

private:
	bool m_IsPaused;

	//Buttons
	GameButton * m_ScoreButton3;
	GameButton * m_ScoreButton5;
	GameButton * m_ScoreButton10;
	GameButton * m_ScoreButtonInf;
	GameButton * m_TimeButton1;
	GameButton * m_TimeButton2;
	GameButton * m_TimeButton5;
	GameButton * m_TimeButtonInf;
	GameButton * m_P1ControlButtonKeyboardArrows;
	GameButton * m_P1ControlButtonKeyboardWASD;
	GameButton * m_P1ControlButtonMouse;
	GameButton * m_P2ControlButtonKeyboardArrows;
	GameButton * m_P2ControlButtonKeyboardWASD;
	GameButton * m_P2ControlButtonMouse;
	GameButton * m_BackButton;

	void updateControlButtons();
};
#endif