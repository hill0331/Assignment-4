//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Credits screen
//	Modified:		October 30th 2013
//

#ifndef CREDITS_SCREEN_H
#define CREDITS_SCREEN_H


#include "../../Screen Manager/Screen.h"

class OpenGLTexture;

class CreditsScreen : public Screen
{
public:
	CreditsScreen();
	~CreditsScreen();

	//CreditsScreen lifecycle methods
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
	//Key Events
	void keyUpEvent(int keyCode);
	//Mouse Events
	void mouseLeftClickUpEvent(float positionX, float positionY);

	float m_TextY;

	//Textures
	OpenGLTexture * m_BkgTexture;
	OpenGLTexture * m_TextBkgTexture;
	OpenGLTexture * m_TextTexture;

	//Fade effect
	float m_CurrentAlpha;
	bool m_TransitionOut;
	std::string m_ScreenToTransition;
};

#endif