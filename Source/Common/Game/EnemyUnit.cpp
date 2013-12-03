//
//  EnemyUnit.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "EnemyUnit.h"
#include "Level.h"
#include "Tiles/Tile.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "../Path/FastPathFinder.h"
#include "../Utils/Logger/Logger.h"
#include "../Screen Manager/ScreenManager.h"

EnemyUnit::EnemyUnit(Level* aLevel):Unit(aLevel)
{
	setScore(10);
}

EnemyUnit::~EnemyUnit()
{

}

const char* EnemyUnit::getType()
{
	return ENEMY_TYPE;
}
void EnemyUnit::paint()
{
	OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorRed());
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2,true,12);
	OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_OUTLINE_COLOR);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, false,12);
	// eyes
	OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorWhite());
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2)-10, getY() + (getHeight() / 2)-5, 4, true,12);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2)+10, getY() + (getHeight() / 2)-5, 4, true,12);
	Tile *player = m_Level->getPlayerTile();
	float eyeX;
	float eyeY;
	float px,py;
	float ex = getX();
	float ey = getY();
	player->getPosition(px,py);

	int dx = (int)(px-ex);
	int dy = (int)(py-ey);
	if (dx == 0)
	{
		eyeX = 0;
	}
	else if (dx < 0)
	{
		eyeX = -2;
	}
	else // dx > 0
	{
		eyeX = +2;
	}
	if (dy == 0)
	{
		eyeY = 0;
	}
	else if (dy < 0)
	{
		eyeY = -2;
	}
	else
	{
		eyeY = +2;
	}
	
	OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorBlack());
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2)-10+eyeX, getY() +eyeY+ (getHeight() / 2)-5, 1, true,12);
	OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2)+10+eyeX, getY() +eyeY+ (getHeight() / 2)-5, 1, true,12);
}

void EnemyUnit::reachedDestination()
{
	if (m_CurrentTile == m_Level->getPlayerTile()) {
		// we're done!
		// GAME OVER MAN...
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);

	}
	setScore(10);
	m_DestinationTile = m_Level->getPlayerTile();
	m_Level->queueForPathFinding(this);

}