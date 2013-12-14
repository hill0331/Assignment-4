//
//  SpawnPoint.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "SpawnPoint.h"
#include "EnemyManager.h"
#include "Tiles/Tile.h"
#include "EnemyUnit.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "../Path/FastPathFinder.h"
#include "../Utils/Logger/Logger.h"

SpawnPoint::SpawnPoint(Level * level, EnemyManager* enemyManager)
{
	m_Level = level;
	m_EnemyManager = enemyManager;
	m_ElapsedTime = 0.0;
	m_SpawnRate = 2.0;
	m_InfiniteSpawn = false;
	m_SpawnQueue = 0;
}

SpawnPoint::~SpawnPoint()
{
    
}

const char* SpawnPoint::getType()
{
    return PLAYER_TYPE;
}
void SpawnPoint::paint()
{
	OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorGray());
	OpenGLRenderer::getInstance()->drawRectangle(getX(), getY(), 32.0f, 32.0f,true);
}

void SpawnPoint::update(double aDelta)
{
	m_ElapsedTime += aDelta;

	if (m_ElapsedTime >= m_SpawnRate)
	{
		if (m_InfiniteSpawn == true || m_SpawnQueue != 0)
		{
			m_ElapsedTime = 0.0;
			// spawn a new unit
			Unit * unit = new EnemyUnit(m_Level, m_EnemyManager);
			unit->setCurrentTile(m_CurrentTile);
			unit->setScore(15);
			unit->reset();
			m_EnemyManager->addEnemyUnit(unit);

			if (m_SpawnQueue > 0)
			{
				m_SpawnQueue--;
			}
		}
	}
}

void SpawnPoint::setCurrentTile(Tile* tile)
{
	m_CurrentTile = tile;
	setPosition(tile->getX(), tile->getY());
}

void SpawnPoint::setSpawnRate(double spawnRate)
{
	m_SpawnRate = spawnRate;
}

void SpawnPoint::SpawnUnits(int spawnCount)
{
	m_SpawnQueue += spawnCount;
}




