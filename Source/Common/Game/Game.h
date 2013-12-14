#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"
#include "../UI/UISideMenu.h"

class UISideMenu;
class UIToggle;
class UIButton;
class GameObject;
class Level;
class UIFont;

class Game : public Screen, public UISideMenuListener
{
public:
	Game();
	~Game();

	//Game lifecycle methods
	void update(double delta);
	void paint();
	void reset();

	//Screen name, must be implemented, it's a pure
	//virtual method in the Screen class
	const char* getName();
	virtual void screenWillAppear();
	Level* getLevel();
	void setLevel(Level* level);
	void setSelectedTile(int tileIndex);

	int getPlayerScore();

private:
	//Mouse Events
	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);
	void keyUpEvent(int keyCode);

	//Menus
	void sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex);
	void sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex);

	//Level pointer
	Level* m_Level;
	UISideMenu* m_TowersMenu;

	//Mouse location
	float m_MouseX;
	float m_MouseY;
	int m_SelectedTileIndex;
	bool m_IsMouseDown;

	//UI
	int m_FastForwardState;
	void cycleFastForward();
	OpenGLTexture * m_FastForward2X;
	OpenGLTexture * m_FastForward5X;
	OpenGLTexture * m_HUDBorderTex;
	UIFont * m_Font;

	void gameOver();
	void drawHUD();

	float m_ElapsedGameTime;
};

#endif