//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Game Over screen
//	Modified:		October 30th 2013
//

#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H

#include "../../Screen Manager/Screen.h"

class OpenGLTexture;
class ButtonGroup;

class GameOverScreen : public Screen
{
public:
	GameOverScreen();
	~GameOverScreen();

	//GameOverScreen lifecycle methods
	void update(double delta);
	void paint();

	//Screen name, must be implemented, it's a pure
	//virtual method in the Screen class
	const char* getName();

	//Screen event method, inherited from the screen class
	void screenWillAppear();

	//Draw Number Function
	void drawNumber(int number, float x, float y);
	
	//Fade efect
	void transitionOut(const char* screenName);
	void buttonPressed(int buttonNumber);

private:
	//Mouse event methods, inherited from Screen
	virtual void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	virtual void mouseLeftClickDownEvent(float positionX, float positionY);
	virtual void mouseRightClickDownEvent(float positionX, float positionY);
	virtual void mouseLeftClickUpEvent(float positionX, float positionY);
	virtual void mouseRightClickUpEvent(float positionX, float positionY);

	//Key up and down event methods, inherited from Screen
	virtual void keyDownEvent(int keyCode);
	virtual void keyUpEvent(int keyCode);

	//Score variables
	short m_LeftGoalsScored;
	short m_LeftSaves;
	short m_RightGoalsScored;
	short m_RightSaves;

	//Textures
	OpenGLTexture * m_BkgTexture;
	OpenGLTexture * m_GameOverHeaderTexture;
	OpenGLTexture** m_ScoreInfoNumbers;

	//Buttons
	ButtonGroup * m_Buttons;

	//Fade effect
	float m_CurrentAlpha;
	bool m_TransitionOut;
	std::string m_ScreenToTransition;
};

#endif