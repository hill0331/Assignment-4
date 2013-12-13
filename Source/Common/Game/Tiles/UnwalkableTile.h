//
//  UnwalkableTile.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef UNWALKABLE_TILE_H
#define UNWALKABLE_TILE_H

#include "Tile.h"


class UnwalkableTile : public Tile
{
public:
	UnwalkableTile(float rotation);
	virtual ~UnwalkableTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
