//
//  WallTileStraight.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WALL_TILE_STRAIGHT_H
#define WALL_TILE_STRAIGHT_H

#include "../Tile.h"


class WallTileStraight : public Tile
{
public:
	WallTileStraight(float rotation);
	virtual ~WallTileStraight();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
