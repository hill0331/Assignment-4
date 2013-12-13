//
//  EnemySpawnTile.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef ENEMY_SAPWN_TILE_H
#define ENEMY_SAPWN_TILE_H

#include "Tile.h"


class EnemySpawnTile : public Tile
{
public:
	EnemySpawnTile(float rotation);
	virtual ~EnemySpawnTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
