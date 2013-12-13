//
//  EmptyTile.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef EMPTY_TILE_H
#define EMPTY_TILE_H

#include "Tile.h"


class EmptyTile : public Tile
{
public:
	EmptyTile(float rotation);
	virtual ~EmptyTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
