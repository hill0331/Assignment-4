//
//  SpawnPoint.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef SPAWN_POINT_H
#define SPAWN_POINT_H

#include "GameObject.h"
#include <vector>
#include "Unit.h"
class Level;
class Tile;
class FastPathFinder;


class SpawnPoint : public GameObject
{
public:
	SpawnPoint(Level* level);
	virtual ~SpawnPoint();

	//Update, paint and reset methods
	void update(double delta);
	void paint();
	//void reset();

	void setSpawnRate(double spawnRate);

	//Implementing GameObject's pure virtual method
	const char* getType();

	void setCurrentTile(Tile* tile);
private:
	double m_ElapsedTime;
	double m_SpawnRate;
	Tile *m_CurrentTile;
	Level * m_Level;
};

#endif