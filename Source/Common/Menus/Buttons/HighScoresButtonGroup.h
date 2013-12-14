//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the High Scores Menu
//	Modified:		December 12th 2013
//

#ifndef HIGH_SCORES_BUTTON_GROUP
#define HIGH_SCORES_BUTTON_GROUP

#include <iostream>
#include "ButtonGroup.h"

class HighScoresButtonGroup : public ButtonGroup
{

public:
	HighScoresButtonGroup();
	virtual ~HighScoresButtonGroup();
	void handleButtonTrigger(int buttonNumber);

private:

};
#endif