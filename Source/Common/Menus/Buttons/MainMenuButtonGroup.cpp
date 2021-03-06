//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the Main Menu
//	Modified:		October 30th 2013
//

#include "MainMenuButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "Button.h"
#include "../MainMenu.h"

MainMenuButtonGroup::MainMenuButtonGroup()
{
	float buttonWidth = 350.0f;
	float buttonHeight = 100.0f;
	float buttonPadding = ScreenManager::getInstance()->getScreenWidth() * 0.045;

	float buttonX = ScreenManager::getInstance()->getScreenWidth() * 0.23;
	float buttonY = (float)ScreenManager::getInstance()->getScreenHeight() * 0.87;


	Button *playButton = new Button(buttonPadding, buttonY, 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/SinglePlayer");

	Button *highScoresButton = new Button(buttonX + buttonPadding, buttonY, 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/highScores");

	Button *settingsButton = new Button(buttonX *2 + buttonPadding, buttonY, 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/settings");

	Button *exitButton = new Button(buttonX*3 + buttonPadding, buttonY, 350.0f, 100.0f, ENABLED_BUTTON,
		"UI/Menus/MainMenu/buttons/Exit");

	addButton(playButton);
	addButton(highScoresButton);
	addButton(settingsButton);
	addButton(exitButton);
}

MainMenuButtonGroup::~MainMenuButtonGroup()
{

}

void MainMenuButtonGroup::handleButtonTrigger(int buttonNumber)
{
	MainMenu* mainMenu = (MainMenu*)ScreenManager::getInstance()->getScreenForName(MAIN_MENU_SCREEN_NAME);
	mainMenu->buttonPressed(buttonNumber);
}
