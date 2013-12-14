//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Victory Screen Code
//	Modified:		December 12th 2013
//

#ifndef VICTORY_SCREEN_H
#define VICTORY_SCREEN_H

#include "Buttons/ButtonGroup.h"
#include "../Screen Manager/Screen.h"

class OpenGLTexture;

class VictoryScreen : public Screen
{
public:
	VictoryScreen();
	~VictoryScreen();

	//VictoryScreen lifecycle methods
	void update(double delta);
	void paint();

	//Screen name, must be implemented, it's a pure
	//virtual method in the Screen class
	const char* getName();

	//Screen event method, inherited from the screen class
	void screenWillAppear();

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

	//Textures
	OpenGLTexture * m_OverlayTexture;
	OpenGLTexture ** m_BkgTextureList;
	int m_CurrentBkgTexture;
	int m_BkgTextureCount;

	//UI
	OpenGLTexture * m_TitleTex;

	float m_BkgTexturePosition;
	float m_BkgAlpha;

	//Buttons
	ButtonGroup * m_Buttons;	

	//Fade effect
	float m_CurrentAlpha;
	bool m_TransitionOut;
	std::string m_ScreenToTransition;
};

#endif