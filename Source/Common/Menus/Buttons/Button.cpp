#include "Button.h"
#include "../../OpenGL/OpenGLRenderer.h"

Button::Button(float x, float y, float width, float height, int state, char* texture)
{
    for (int i = 0; i < 5; i++)
    {
        m_Textures[i] = NULL;
    }

	//Setup textures
	std::string strTexture = std::string(texture);
	std::string enabledTexture = strTexture + "0";
	std::string disabledTexture = strTexture + "1";
	std::string inFocusTexture = strTexture + "2";
	std::string pressedTexture = strTexture + "3";
	std::string triggeredTexture = strTexture + "4";

	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setState(state);
	setTextureAt(0, enabledTexture.c_str());
	setTextureAt(1, disabledTexture.c_str());
	setTextureAt(2, inFocusTexture.c_str());
	setTextureAt(3, pressedTexture.c_str());
	setTextureAt(4, triggeredTexture.c_str());

	m_Alpha = 1.0f;

}

Button::~Button()
{
    
}

void Button::update(double delta)
{
    
}

void Button::setTextureAt(int state, const char* textureName)
{
    if (m_Textures[state] != NULL)
    {
        delete m_Textures[state];
        m_Textures[state] = NULL;
    }
    m_Textures[state] = new OpenGLTexture(textureName);
}

void Button::paint()
{
    OpenGLRenderer::getInstance()->drawTexture(m_Textures[m_State], getX(), getY(), getWidth(), getHeight());
}

void Button::reset()
{
    
}
bool Button::inButton(float x, float y)
{
    std::cout << "in button: x: " << x << " y: " << y << std::endl;
    // default is for rectangular buttons.  subclasses can be different
    if (x < getX() || x > getX()+getWidth())
    {
        return false;
    }
    if (y < getY() || y > getY()+getHeight())
    {
        return false;
    }
    return true;
}

void Button::setState(int state)
{
    m_State = state;
}

int Button::getState()
{
    return m_State;
}

float Button::getAlpha()
{
	return m_Alpha;
}

void Button::setAlpha(float alpha)
{
	m_Alpha = alpha;

	for (int i = 0; i < 5; i ++)
	{
		if (m_Textures[i] != NULL)
		{
			m_Textures[i]->setAlpha(m_Alpha);
		}
	}
}

const char* Button::getType()
{
	return BUTTON_TYPE;
}