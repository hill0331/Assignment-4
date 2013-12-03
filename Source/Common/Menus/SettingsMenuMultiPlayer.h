//
//	Student:		Bradley Hill
//	Creation date:	October 15th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		Code for the MultiPlayer Settings Menu
//	Modified:		October 30th 2013
//

#ifndef SETTINGS_MENU_2_PLAYER_H
#define SETTINGS_MENU_2_PLAYER_H

#include "../../Screen Manager/Screen.h"

class OpenGLTexture;
class SettingsMenuMultiPlayerButtonGroup;

class SettingsMenuMultiPlayer : public Screen
{
public:
	SettingsMenuMultiPlayer();
	~SettingsMenuMultiPlayer();

	//SettingsMenuMultiPlayer lifecycle methods
	void update(double delta);
	void paint();

	//Screen name, must be implemented, it's a pure
	//virtual method in the Screen class
	const char* getName();

	//Screen event method, inherited from the screen class
	void screenWillAppear();

	void transitionOut(const char* screenName);
	void buttonPressed(int buttonNumber);

	//Get and set
	float getScoreLimit();
	float getTimeLimit();
	float getPlayer1Controls();
	float getPlayer2Controls();

	void setScoreLimit(float score);
	void setTimeLimit(float time);
	void setPlayer1Controls(float controls);
	void setPlayer2Controls(float controls);

	void setIsPaused(bool isPaused);

private:
	//Mouse event methods, inherited from Screen
	virtual void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	virtual void mouseLeftClickDownEvent(float positionX, float positionY);
	virtual void mouseLeftClickUpEvent(float positionX, float positionY);

	//Key up and down event methods, inherited from Screen
	virtual void keyDownEvent(int keyCode);
	virtual void keyUpEvent(int keyCode);

	//Textures
	OpenGLTexture * m_BkgTexture;
	OpenGLTexture * m_ScoreTexture;
	OpenGLTexture * m_TimeTexture;
	OpenGLTexture * m_Player1ControlsTexture;
	OpenGLTexture * m_Player2ControlsTexture;

	//Buttons	
	SettingsMenuMultiPlayerButtonGroup * m_Buttons;

	bool m_IsPaused;

	//Settings variables
	bool m_IsMultiPlayer;
	float m_ScoreLimit;
	float m_TimeLimit;
	float m_Difficulty;
	float m_Player1Controls;
	float m_Player2Controls;

	//Window
	float m_ScreenWidth;
	float m_ScreenHeight;

	//Fade effect
	float m_CurrentAlpha;
	bool m_TransitionOut;
	std::string m_ScreenToTransition;

};

#endif