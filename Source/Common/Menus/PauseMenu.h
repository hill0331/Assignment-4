#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "../../Screen Manager/Screen.h"

class OpenGLTexture;
class ButtonGroup;

class PauseMenu : public Screen
{
public:
	PauseMenu();
	~PauseMenu();

	//PauseMenu lifecycle methods
	void update(double delta);
	void paint();

	//Screen name, must be implemented, it's a pure
	//virtual method in the Screen class
	const char* getName();

	//Screen event method, inherited from the screen class
	void screenWillAppear();

	void setIsMultiPlayer(bool isMultiPlayer);

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
	OpenGLTexture * m_BkgTexture;

	//Buttons
	ButtonGroup * m_Buttons;

	//Settings
	bool m_IsMultiPlayer;

	//Fade effect
	float m_CurrentAlpha;
	bool m_TransitionOut;
	std::string m_ScreenToTransition;
};

#endif