//
//  WallTileEdgeStraight.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WALL_TILE_EDGE_STRAIGHT_H
#define WALL_TILE_EDGE_STRAIGHT_H

#include "../Tile.h"


class WallTileEdgeStraight : public Tile
{
public:
	WallTileEdgeStraight(float rotation);
	virtual ~WallTileEdgeStraight();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
