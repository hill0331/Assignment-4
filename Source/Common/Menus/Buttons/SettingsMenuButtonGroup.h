//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the High Scores Menu
//	Modified:		December 12th 2013
//

#ifndef SETTINGS_MENU_BUTTON_GROUP
#define SETTINGS_MENU_BUTTON_GROUP

#include <iostream>
#include "ButtonGroup.h"

class SettingsMenuButtonGroup : public ButtonGroup
{

public:
	SettingsMenuButtonGroup();
	virtual ~SettingsMenuButtonGroup();
	void handleButtonTrigger(int buttonNumber);

private:

};
#endif