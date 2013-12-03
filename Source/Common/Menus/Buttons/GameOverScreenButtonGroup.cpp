//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Game Over menu buttons
//	Modified:		October 30th 2013
//

#include "GameOverScreenButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "GameButton.h"
#include "../Menus/GameOverScreen.h"

GameOverScreenButtonGroup::GameOverScreenButtonGroup()
{
	float buttonWidth = 250.0f;
	float buttonHeight = 75.0f;
	float buttonPadding = 100.0f;
	float buttonY = 650;
	float buttonInitialX = (ScreenManager::getInstance()->getScreenWidth() - (buttonWidth * 2 + buttonPadding)) / 2;

	GameButton *restartButton = new GameButton(buttonInitialX, buttonY, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/PauseMenu/buttons/restart0",
		"/UI/PauseMenu/buttons/restart1",
		"/UI/PauseMenu/buttons/restart2",
		"/UI/PauseMenu/buttons/restart3",
		"/UI/PauseMenu/buttons/restart0");

	GameButton *mainMenuButton = new GameButton(buttonInitialX + buttonPadding + buttonWidth, buttonY, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"UI/PauseMenu/buttons/mainMenu0",
		"UI/PauseMenu/buttons/mainMenu1",
		"UI/PauseMenu/buttons/mainMenu2",
		"UI/PauseMenu/buttons/mainMenu3",
		"UI/PauseMenu/buttons/mainMenu0");

	addGameButton(restartButton);
	addGameButton(mainMenuButton);
}

GameOverScreenButtonGroup::~GameOverScreenButtonGroup()
{

}

void GameOverScreenButtonGroup::handleButtonTrigger(int buttonNumber)
{
	GameOverScreen* gameOverScreen = (GameOverScreen*)ScreenManager::getInstance()->getScreenForName(GAME_OVER_SCREEN_NAME);
	gameOverScreen->buttonPressed(buttonNumber);
}
