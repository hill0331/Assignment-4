
#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "../../OpenGL/OpenGLTexture.h"
#include "../../Game/GameObject.h"
#include "../../Constants/Constants.h"


#define ENABLED_BUTTON 0
#define DISABLED_BUTTON 1
#define IN_FOCUS_BUTTON 2
#define PRESSED_BUTTON 3
#define TRIGGERED_BUTTON 4

class OpenGLTexture;

class Button : public GameObject
{

public:
	Button(float x, float y, float width, float height, int state, char* texture);
	~Button();	

	//Virtual method to easily determine type of object
	virtual const char* getType();

	void update(double delta);
	void paint();
	void reset();

	void setState(int state);
	int getState();
	void setTextureAt(int state, const char* textureName);
	virtual bool inButton(float x, float y);

	float getAlpha();
	void setAlpha(float alpha);

private:
	int m_State;
	int m_Alpha;
	OpenGLTexture * m_Textures[5]; // one per state

};

#endif 