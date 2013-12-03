//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the Pause Menu
//	Modified:		October 30th 2013
//

#include "PauseMenuButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "GameButton.h"
#include "../Menus/PauseMenu.h"

PauseMenuButtonGroup::PauseMenuButtonGroup()
{
	float buttonWidth = 250.0f;
	float buttonHeight = 75.0f;
	float buttonYPadding = 5.0f;
	float buttonX = (ScreenManager::getInstance()->getScreenWidth() - buttonWidth) / 2;
	float buttonInitialY = ScreenManager::getInstance()->getScreenHeight() * 0.7f;


	GameButton *resumeButton = new GameButton(buttonX, buttonInitialY - (buttonHeight * 3), buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/PauseMenu/buttons/resume0",
		"/UI/PauseMenu/buttons/resume1",
		"/UI/PauseMenu/buttons/resume2",
		"/UI/PauseMenu/buttons/resume3",
		"/UI/PauseMenu/buttons/resume0");

	GameButton *restartButton = new GameButton(buttonX, buttonInitialY - (buttonHeight * 2) + buttonYPadding, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/PauseMenu/buttons/restart0",
		"/UI/PauseMenu/buttons/restart1",
		"/UI/PauseMenu/buttons/restart2",
		"/UI/PauseMenu/buttons/restart3",
		"/UI/PauseMenu/buttons/restart0");

	GameButton *settingsButton = new GameButton(buttonX, buttonInitialY - (buttonHeight) + buttonYPadding * 2, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/PauseMenu/buttons/settings0",
		"/UI/PauseMenu/buttons/settings1",
		"/UI/PauseMenu/buttons/settings2",
		"/UI/PauseMenu/buttons/settings3",
		"/UI/PauseMenu/buttons/settings0");


	GameButton *mainMenuButton = new GameButton(buttonX, buttonInitialY + buttonYPadding * 3, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"UI/PauseMenu/buttons/mainMenu0",
		"UI/PauseMenu/buttons/mainMenu1",
		"UI/PauseMenu/buttons/mainMenu2",
		"UI/PauseMenu/buttons/mainMenu3",
		"UI/PauseMenu/buttons/mainMenu0");

	addGameButton(resumeButton);
	addGameButton(restartButton);
	addGameButton(settingsButton);
	addGameButton(mainMenuButton);
}

PauseMenuButtonGroup::~PauseMenuButtonGroup()
{

}

void PauseMenuButtonGroup::handleButtonTrigger(int buttonNumber)
{
	PauseMenu* pauseMenu = (PauseMenu*)ScreenManager::getInstance()->getScreenForName(PAUSE_MENU_NAME);
	pauseMenu->buttonPressed(buttonNumber);
}
