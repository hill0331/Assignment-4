#ifndef BUTTON_GROUP_H
#define BUTTON_GROUP_H

#include <iostream>
#include "../../Game/GameObject.h"
#include <vector>
#include "Button.h"

class ButtonGroup: public GameObject
{
public:
    ButtonGroup();
    ~ButtonGroup();

    virtual void update(double delta);
    virtual void paint();
    virtual void reset();

	//Virtual method to easily determine type of object
	virtual const char* getType();

    void addButton(Button *button);
	virtual void initializeGroup();

	void setGroupAlpha(float alpha);
    virtual void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
    virtual void mouseLeftClickDownEvent(float positionX, float positionY);
    virtual void mouseRightClickDownEvent(float positionX, float positionY);
    virtual void mouseLeftClickUpEvent(float positionX, float positionY);
    virtual void mouseRightClickUpEvent(float positionX, float positionY);
    
    //Key up and down event methods, inherited from Screen
    virtual void keyDownEvent(int keyCode);
    virtual void keyUpEvent(int keyCode);
    virtual void handleButtonTrigger(int buttonNumber) = 0;

protected:
    std::vector<Button*> m_Buttons;
    int m_SelectedButton;
	int m_PressedButton;
};

#endif
