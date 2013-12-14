//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the High Scores Menu
//	Modified:		December 12th 2013
//

#include "HighScoresButtonGroup.h"
#include "../../Screen Manager/ScreenManager.h"
#include "Button.h"
#include "../HighScoresScreen.h"

HighScoresButtonGroup::HighScoresButtonGroup()
{
	float buttonWidth = 200.0f;
	float buttonHeight = 75.0f;	

	float buttonX = ScreenManager::getInstance()->getScreenWidth() * 0.03;
	float buttonY = (float)ScreenManager::getInstance()->getScreenHeight() * 0.87;


	Button *backButton = new Button(buttonX, buttonY, buttonWidth, buttonHeight, ENABLED_BUTTON,
		"/UI/Menus/HighScores/buttons/back");	

	addButton(backButton);
}

HighScoresButtonGroup::~HighScoresButtonGroup()
{

}

void HighScoresButtonGroup::handleButtonTrigger(int buttonNumber)
{
	HighScoresScreen* highScoresScreen = (HighScoresScreen*)ScreenManager::getInstance()->getScreenForName(HIGH_SCORES_SCREEN_NAME);
	highScoresScreen->buttonPressed(buttonNumber);
}
