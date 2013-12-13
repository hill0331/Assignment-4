//
//  PlayerSpawnTile.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PLAYER_SPAWN_TILE_H
#define PLAYER_SPAWN_TILE_H

#include "Tile.h"


class PlayerSpawnTile : public Tile
{
public:
	PlayerSpawnTile(float rotation);
	virtual ~PlayerSpawnTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
