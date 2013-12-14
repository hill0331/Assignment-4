//
//	Student:		Bradley Hill
//	Creation date:	December 12th 2013
//	Course number:	GAM1514
//	Professor:		Dan Lingman
//	Purpose:		High Scores Screen Code
//	Modified:		December 12th 2013
//

#ifndef HIGH_SCORES_SCREEN_H
#define HIGH_SCORES_SCREEN_H

#include "Buttons/ButtonGroup.h"
#include "../Screen Manager/Screen.h"

class OpenGLTexture;
class UIFont;

class HighScoresScreen : public Screen
{
public:
	HighScoresScreen();
	~HighScoresScreen();

	//HighScoresScreen lifecycle methods
	void update(double delta);
	void paint();

	//File loading/saving
	void loadHighScores();
	void saveHighScores();
	void addScore(int score);

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

	void drawHighScores();

	std::vector<int> m_HighScores;

	//Textures
	OpenGLTexture * m_OverlayTexture;
	OpenGLTexture ** m_BkgTextureList;
	int m_CurrentBkgTexture;
	int m_BkgTextureCount;

	float m_BkgTexturePosition;
	float m_BkgAlpha;

	//UI
	OpenGLTexture * m_TitleTex;
	UIFont * m_Font;

	//Buttons
	ButtonGroup * m_Buttons;	

	//Fade effect
	float m_CurrentAlpha;
	bool m_TransitionOut;
	std::string m_ScreenToTransition;
};

#endif