//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the Main Menu
//	Modified:		October 30th 2013
//

#include "VictoryScreenButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "Button.h"
#include "../VictoryScreen.h"

VictoryScreenButtonGroup::VictoryScreenButtonGroup()
{
	float buttonWidth = 350.0f;
	float buttonHeight = 100.0f;
	float buttonPadding = ScreenManager::getInstance()->getScreenWidth() * 0.15;

	float buttonX = ScreenManager::getInstance()->getScreenWidth() * 0.23;
	float buttonY = (float)ScreenManager::getInstance()->getScreenHeight() * 0.87;


	Button *playButton = new Button(buttonPadding, buttonY, 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/SinglePlayer");

	Button *highScoresButton = new Button(buttonX + buttonPadding, buttonY, 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/HighScores");	

	Button *exitButton = new Button(buttonX*2 + buttonPadding, buttonY, 350.0f, 100.0f, ENABLED_BUTTON,
		"UI/Menus/MainMenu/buttons/Exit");

	addButton(playButton);
	addButton(highScoresButton);	
	addButton(exitButton);
}

VictoryScreenButtonGroup::~VictoryScreenButtonGroup()
{

}

void VictoryScreenButtonGroup::handleButtonTrigger(int buttonNumber)
{
	VictoryScreen* victoryScreen = (VictoryScreen*)ScreenManager::getInstance()->getScreenForName(VICTORY_SCREEN_NAME);
	victoryScreen->buttonPressed(buttonNumber);
}