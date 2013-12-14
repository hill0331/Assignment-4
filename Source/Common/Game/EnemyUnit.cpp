//
//  EnemyUnit.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "EnemyUnit.h"
#include "Level.h"
#include "EnemyManager.h"
#include "Tiles/Tile.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "../Path/FastPathFinder.h"
#include "../Utils/Logger/Logger.h"
#include "../Screen Manager/ScreenManager.h"

EnemyUnit::EnemyUnit(Level* aLevel, EnemyManager * enemyManager) :Unit(aLevel, enemyManager)
{
	m_UnitHealth = 10;
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
	
}

void EnemyUnit::reachedDestination()
{
	if (m_CurrentTile == m_EnemyManager->getTargetTile()) 
	{
		m_Level->decrementLives(1);		
		setIsActive(false);
	}
	else
	{

		setScore(10);
		setDestinationTile(m_EnemyManager->getTargetTile());
	}

}

int EnemyUnit::getUnitHealth()
{
	return m_UnitHealth;
}

void EnemyUnit::setUnitHealth(int health)
{
	m_UnitHealth = health;
}

void EnemyUnit::decrementUnitHealth(int healthToSubtract)
{
	m_UnitHealth -= healthToSubtract;
}