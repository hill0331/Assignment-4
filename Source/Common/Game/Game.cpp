#include "Game.h"
#include "GameObject.h"
#include "Level.h"
#include <sstream>
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UISideMenu.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"
#include "../UI/UIFont.h"

Game::Game() :
m_SelectedTileIndex(-1),
m_MouseX(0.0f),
m_MouseY(0.0f),
m_IsMouseDown(false),
m_Level(NULL),
m_TowersMenu(NULL),
m_FastForwardState(1),
m_ElapsedGameTime(0)
{
	//Create the level object
	m_Level = new Level();

	//Create the Tiles menu items
	m_TowersMenu = new UISideMenu(this, SideMenuRight);

	//UI
	m_FastForward2X = new OpenGLTexture(FAST_FOARWARD_2X_TEXTURE);
	m_FastForward5X = new OpenGLTexture(FAST_FOARWARD_5X_TEXTURE);
	m_HUDBorderTex = new OpenGLTexture(HUD_BORDER_TEXTURE);

	m_Font = new UIFont("fonts/TechFont");	

	//Reset everything
	reset();
}

Game::~Game()
{
	//Delete the level object
	if (m_Level != NULL)
	{
		delete m_Level;
		m_Level = NULL;
	}

	if (m_Font != NULL)
	{
		delete m_Font;
		m_Font = NULL;
	}

	if (m_TowersMenu != NULL)
	{
		delete m_TowersMenu;
		m_TowersMenu = NULL;
	}

	if (m_FastForward2X != NULL)
	{
		delete m_FastForward2X;
		m_FastForward2X = NULL;
	}

	if (m_FastForward5X != NULL)
	{
		delete m_FastForward5X;
		m_FastForward5X = NULL;
	}
	if (m_HUDBorderTex != NULL)
	{
		delete m_HUDBorderTex;
		m_HUDBorderTex = NULL;
	}
}
void Game::screenWillAppear()
{
	if (m_Level != NULL)
	{
		m_Level->reset();
	}
}

void Game::update(double delta)
{
	m_ElapsedGameTime += delta * m_FastForwardState;

	if (m_Level != NULL)
	{
		for (int i = 0; i < m_FastForwardState; i++)
		{
			m_Level->update(delta);
		}
	}	

	if (m_TowersMenu != NULL)
	{
		m_TowersMenu->update(delta);
	}
}

void Game::paint()
{
	if (m_Level != NULL)
	{
		m_Level->paint();
	}

	if (m_FastForwardState == 2)
	{
		OpenGLRenderer::getInstance()->drawTexture(m_FastForward2X, 5.0f, 5.0f);
	}
	else if (m_FastForwardState == 5)
	{
		OpenGLRenderer::getInstance()->drawTexture(m_FastForward5X, 5.0f, 5.0f);
	}

	//Text border
	OpenGLRenderer::getInstance()->drawTexture(m_HUDBorderTex, (getWidth() - m_HUDBorderTex->getTextureWidth()) /2, 0.0f);

	//Text based UI
	if (m_Font != NULL)
	{
		//Time
		std::ostringstream oss;
		oss << (int)m_ElapsedGameTime;

		std::string time = "TIME   ";
		time.append(oss.str());

		m_Font->setText(time.c_str());
		m_Font->draw(getWidth() * 0.45, 5.0f);

		//Lives	
		oss.str(std::string());
		oss << m_Level->getNumberOfLives();
		 
		std::string lives = "LIVES   ";
		lives.append(oss.str());
		
		m_Font->setText(lives.c_str());
		m_Font->draw(getWidth() * 0.29, 5.0f);

		//Score
		oss.str(std::string());
		oss << m_Level->getPlayerScore();

		std::string score = "SCORE   ";
		score.append(oss.str());

		m_Font->setText(score.c_str());
		m_Font->draw(getWidth() * 0.58, 5.0f);
	}

	if (m_TowersMenu != NULL)
	{
		m_TowersMenu->paint();
	}
}

void Game::reset()
{
	if (m_Level != NULL)
	{
		m_Level->reset();
	}

	m_ElapsedGameTime = 0;
}



const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

Level* Game::getLevel()
{
	return m_Level;
}

void Game::setLevel(Level *level)
{
	if (m_Level != NULL)
	{
		delete m_Level;
		m_Level = NULL;
	}
	m_Level = level;
}

void Game::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	if (m_TowersMenu != NULL)
	{
		m_TowersMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
	}

	if (m_Level != NULL)
	{
		if (m_SelectedTileIndex != -1 && m_IsMouseDown == true)
		{
			m_Level->setTileTypeAtPosition((TileType)m_SelectedTileIndex, positionX, positionY, 0.0f);
		}
	}

	m_MouseX = positionX;
	m_MouseY = positionY;
}



void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_IsMouseDown = false;

	if (m_Level != NULL)
	{
		m_Level->mouseLeftClickUpEvent(positionX, positionY);
	}

	//Notify the towers menu of the mouse event
	if (m_TowersMenu != NULL)
	{
		m_TowersMenu->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void Game::cycleFastForward()
{
	if (m_FastForwardState == 1)
	{
		m_FastForwardState = 2;
	}
	else if (m_FastForwardState == 2)
	{
		m_FastForwardState = 5;
	}
	else
	{
		m_FastForwardState = 1;
	}
}

void Game::keyUpEvent(int keyCode)
{
	if (keyCode == KEYCODE_TAB)
	{
		if (m_TowersMenu != NULL)
		{
			m_TowersMenu->isShowing() == true ? m_TowersMenu->hide() : m_TowersMenu->show();
		}

	}
	else if (keyCode == KEYCODE_F)
	{
		cycleFastForward();
	}
	else
	{
		if (m_Level != NULL)
		{
			m_Level->keyUpEvent(keyCode);
		}
	}
}

void Game::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{

}

void Game::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{

}


