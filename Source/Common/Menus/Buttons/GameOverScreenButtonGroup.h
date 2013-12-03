//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Game Over menu buttons
//	Modified:		October 30th 2013
//

#ifndef GAME_OVER_SCREEN_BUTTON_GROUP
#define GAME_OVER_SCREEN_BUTTON_GROUP

#include <iostream>
#include "ButtonGroup.h"

class GameOverScreenButtonGroup : public ButtonGroup
{

public:
	GameOverScreenButtonGroup();
	virtual ~GameOverScreenButtonGroup();
	void handleButtonTrigger(int buttonNumber);

private:

};
#endif