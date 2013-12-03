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
	float buttonX = (ScreenManager::getInstance()->getScreenWidth() - buttonWidth) / 2;
	float buttonInitialY = (float)ScreenManager::getInstance()->getScreenHeight() * 0.8;


	Button *singlePlayerButton = new Button(buttonX, buttonInitialY - (buttonHeight * 3), 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/SinglePlayer");

	Button *multiPlayerButton = new Button(buttonX, buttonInitialY - (buttonHeight * 2), 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/MultiPlayer");

	Button *creditsButton = new Button(buttonX, buttonInitialY - (buttonHeight), 350.0f, 100.0f, ENABLED_BUTTON,
		"/UI/Menus/MainMenu/buttons/Credits");

	Button *exitButton = new Button(buttonX, buttonInitialY, 350.0f, 100.0f, ENABLED_BUTTON,
		"UI/Menus/MainMenu/buttons/Exit");

	addButton(singlePlayerButton);
	addButton(multiPlayerButton);
	addButton(creditsButton);
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
