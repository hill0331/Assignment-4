//
//  WallTileCorner90.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WALL_TILE_CORNER_90_H
#define WALL_TILE_CORNER_90_H

#include "../Tile.h"


class WallTileCorner90 : public Tile
{
public:
	WallTileCorner90(float rotation);
	virtual ~WallTileCorner90();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
