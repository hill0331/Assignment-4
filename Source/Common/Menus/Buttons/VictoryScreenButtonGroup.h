//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the Main Menu
//	Modified:		October 30th 2013
//

#ifndef VICTORY_SCREEN_BUTTON_GROUP
#define VICTORY_SCREEN_BUTTON_GROUP

#include <iostream>
#include "ButtonGroup.h"

class VictoryScreenButtonGroup : public ButtonGroup
{

public:
	VictoryScreenButtonGroup();
	virtual ~VictoryScreenButtonGroup();
	void handleButtonTrigger(int buttonNumber);

private:

};
#endif