//
//  PavementTile.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PAVEMENT_TILE_H
#define PAVEMENT_TILE_H

#include "Tile.h"


class PavementTile : public Tile
{
public:
	PavementTile(float rotation);
	virtual ~PavementTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
