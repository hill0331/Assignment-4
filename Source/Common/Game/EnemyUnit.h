//
//  EnemyUnit.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef ENEMY_UNIT_H
#define ENEMY_UNIT_H

#include "GameObject.h"
#include <vector>
#include "Unit.h"

class Level;
class Tile;
class FastPathFinder;
class EnemyManager;
class OpenGLTexture;

class EnemyUnit : public Unit
{
public:
	EnemyUnit(Level* level, EnemyManager * enemyManager);
	virtual ~EnemyUnit();

	//Update, paint and reset methods
	//void update(double delta);
	void paint();
	//void reset();

	//Implementing GameObject's pure virtual method
	const char* getType();

	//Setter methods for the current and destination tiles
	void reachedDestination();
	void destroyed();

	int getUnitHealth();
	void setUnitHealth(int health);
	void decrementUnitHealth(int healthToSubtract);

protected:
	int m_UnitHealth;

	float m_Rotation;
	float m_PrevX;
	float m_PrevY;

	OpenGLTexture * m_Texture;

};

#endif