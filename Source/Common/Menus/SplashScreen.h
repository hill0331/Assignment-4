//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the Splash screen
//	Modified:		October 30th 2013
//

#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H


#include "../Screen Manager/Screen.h"

class OpenGLTexture;

class SplashScreen : public Screen
{
public:
	SplashScreen();
	~SplashScreen();

	//SplashScreen lifecycle methods
	void update(double delta);
	void paint();

	//Screen name, must be implemented, it's a pure
	//virtual method in the Screen class
	const char* getName();

	//Screen event method, inherited from the screen class
	void screenWillAppear();

private:
	//Key Events
	void keyUpEvent(int keyCode);
	//Mouse Events
	void mouseLeftClickUpEvent(float positionX, float positionY);

	//Textures
	OpenGLTexture * m_LogoTexture;	

	float m_CurrentAlpha;
	float m_CurrentAlpha2;
	bool m_Transition;

};

#endif