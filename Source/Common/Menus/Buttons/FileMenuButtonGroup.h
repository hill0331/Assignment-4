//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Button code for the Main Menu
//	Modified:		October 30th 2013
//

#ifndef FILE_MENU_BUTTON_GROUP
#define FILE_MENU_BUTTON_GROUP

#include <iostream>
#include "ButtonGroup.h"

class FileMenuButtonGroup : public ButtonGroup
{

public:
	FileMenuButtonGroup();
	virtual ~FileMenuButtonGroup();
	void handleButtonTrigger(int buttonNumber);

private:

};
#endif