//
//  EnemyUnit.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//	Modified by Bradley Hill - December 13 2013
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
	m_Texture = new OpenGLTexture(ENEMY_TANK_TEXTURE);

	m_Rotation = 0.0f;
	m_PrevX = getX();
	m_PrevY = getY();
}

EnemyUnit::~EnemyUnit()
{
	if (m_Texture != NULL)
	{
		delete m_Texture;
		m_Texture = NULL;
	}
}

const char* EnemyUnit::getType()
{
	return ENEMY_TYPE;
}
void EnemyUnit::paint()
{
	//Orient tank
	if (m_PrevX > getX())
	{
		m_Rotation = 270.0f;
	}
	else if (m_PrevX < getX())
	{
		m_Rotation = 90.0f;
	}
	else if (m_PrevY > getY())
	{
		m_Rotation = 0.0f;
	}
	else if (m_PrevY < getY())
	{
		m_Rotation = 180.0f;
	}

	OpenGLRenderer::getInstance()->drawTexture(m_Texture, getX(), getY(), m_Rotation);	

	m_PrevX = getX();
	m_PrevY = getY();
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

void EnemyUnit::destroyed()
{
	m_Level->addToEnemiesDestroyed(1);
	m_Level->addToPlayerScore(5);
	setIsActive(false);
}

int EnemyUnit::getUnitHealth()
{
	return m_UnitHealth;
}

void EnemyUnit::setUnitHealth(int health)
{
	m_UnitHealth = health;

	if (m_UnitHealth <= 0)
	{
		destroyed();
	}
}

void EnemyUnit::decrementUnitHealth(int healthToSubtract)
{
	m_UnitHealth -= healthToSubtract;

	if (m_UnitHealth <= 0)
	{
		destroyed();
	}
}