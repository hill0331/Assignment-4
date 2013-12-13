//
//  WallTileEdgeFiller.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef WALL_TILE_EDGE_FILLER
#define WALL_TILE_EDGE_FILLER

#include "../Tile.h"


class WallTileEdgeFiller : public Tile
{
public:
	WallTileEdgeFiller(float rotation);
	virtual ~WallTileEdgeFiller();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
