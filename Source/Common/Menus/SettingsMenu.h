//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		High Scores Screen Code
//	Modified:		December 12th 2013
//

#ifndef SETTINGS_MENU_SCREEN_H
#define SETTINGS_MENU_SCREEN_H

#include "Buttons/ButtonGroup.h"
#include "../Screen Manager/Screen.h"

class OpenGLTexture;
class UIFont;

class SettingsMenu : public Screen
{
public:
	SettingsMenu();
	~SettingsMenu();

	//SettingsMenu lifecycle methods
	void update(double delta);
	void paint();

	//File loading/saving
	void loadSettings();
	void saveSettings();

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

	float m_BkgTexturePosition;
	float m_BkgAlpha;

	//UI
	OpenGLTexture * m_TitleTex;

	//Settings
	int m_Difficulty;

	//Buttons
	ButtonGroup * m_Buttons;	

	//Fade effect
	float m_CurrentAlpha;
	bool m_TransitionOut;
	std::string m_ScreenToTransition;
};

#endif