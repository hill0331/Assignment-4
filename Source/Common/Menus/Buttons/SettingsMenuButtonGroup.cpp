//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the Settings Menu
//	Modified:		December 13th 2013
//

#include "SettingsMenuButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "Button.h"
#include "../SettingsMenu.h"

SettingsMenuButtonGroup::SettingsMenuButtonGroup()
{
	float buttonWidth = 200.0f;
	float buttonHeight = 75.0f;	

	float buttonX = ScreenManager::getInstance()->getScreenWidth() * 0.03;
	float buttonY = (float)ScreenManager::getInstance()->getScreenHeight() * 0.87;

	float diffPadding = 50;
	float diffWidth = 200;
	float diffInitialX = (ScreenManager::getInstance()->getScreenWidth() - (diffWidth * 3 + diffPadding * 2)) / 2;
	float diffY = ScreenManager::getInstance()->getScreenHeight() * 0.4;

	Button * buttonEasy = new Button(diffInitialX, diffY, diffWidth, 75.0f, ENABLED_BUTTON,
		"/UI/Menus/SettingsMenu/buttons/easy");

	Button * buttonNormal = new Button(diffInitialX + (diffWidth + diffPadding), diffY, diffWidth, 75.0f, ENABLED_BUTTON,
		"/UI/Menus/SettingsMenu/buttons/normal");

	Button * buttonHard = new Button(diffInitialX + (diffWidth + diffPadding) * 2, diffY, diffWidth, 75.0f, ENABLED_BUTTON,
		"/UI/Menus/SettingsMenu/buttons/hard");

	Button *backButton = new Button(buttonX, buttonY, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/SettingsMenu/buttons/back");	

	addButton(buttonEasy);
	addButton(buttonNormal);
	addButton(buttonHard);
	addButton(backButton);
}

SettingsMenuButtonGroup::~SettingsMenuButtonGroup()
{

}

void SettingsMenuButtonGroup::handleButtonTrigger(int buttonNumber)
{
	SettingsMenu* settingsMenu = (SettingsMenu*)ScreenManager::getInstance()->getScreenForName(SETTINGS_MENU_SCREEN_NAME);
	settingsMenu->buttonPressed(buttonNumber);
}
