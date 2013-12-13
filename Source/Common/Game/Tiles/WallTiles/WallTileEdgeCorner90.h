//
//  WallTileEdgeCorner90.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WALL_TILE_EDGE_CORNER_90
#define WALL_TILE_EDGE_CORNER_90

#include "../Tile.h"


class WallTileEdgeCorner90 : public Tile
{
public:
	WallTileEdgeCorner90(float rotation);
	virtual ~WallTileEdgeCorner90();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
