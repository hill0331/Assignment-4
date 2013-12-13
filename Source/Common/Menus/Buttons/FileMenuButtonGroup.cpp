//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the File Menu
//	Modified:		December 12th 2013
//

#include "FileMenuButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "Button.h"
#include "../FileMenu.h"

FileMenuButtonGroup::FileMenuButtonGroup()
{
	float buttonWidth = 220.0f;
	float buttonHeight = 100.0f;
	float buttonSpacing = ScreenManager::getInstance()->getScreenHeight() * 0.15;

	float row1ButtonX = ScreenManager::getInstance()->getScreenWidth() * 0.35;
	float row2ButtonX = ScreenManager::getInstance()->getScreenWidth() * 0.55;
	float buttonInitialY = (float)ScreenManager::getInstance()->getScreenHeight() * 0.3;


	Button *level1Button = new Button(row1ButtonX, buttonInitialY, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/FileMenu/buttons/Level1-");

	Button *level2Button = new Button(row1ButtonX, buttonInitialY + buttonSpacing, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/FileMenu/buttons/Level2-");

	Button *level3Button = new Button(row1ButtonX, buttonInitialY + buttonSpacing * 2, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/FileMenu/buttons/Level3-");

	Button *level4Button = new Button(row2ButtonX, buttonInitialY, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/FileMenu/buttons/Level4-");

	Button *level5Button = new Button(row2ButtonX, buttonInitialY + buttonSpacing, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/FileMenu/buttons/Level5-");

	Button *level6Button = new Button(row2ButtonX, buttonInitialY + buttonSpacing * 2, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/FileMenu/buttons/Level6-");

	addButton(level1Button);
	addButton(level2Button);
	addButton(level3Button);
	addButton(level4Button);
	addButton(level5Button);
	addButton(level6Button);
}

FileMenuButtonGroup::~FileMenuButtonGroup()
{

}

void FileMenuButtonGroup::handleButtonTrigger(int buttonNumber)
{
	FileMenu* mainMenu = (FileMenu*)ScreenManager::getInstance()->getScreenForName(FILE_MENU_SCREEN_NAME);
	mainMenu->buttonPressed(buttonNumber);
}
