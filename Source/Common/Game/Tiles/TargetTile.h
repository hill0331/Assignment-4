//
//  TargetTile.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef TARGET_TILE_H
#define TARGET_TILE_H

#include "Tile.h"


class TargetTile : public Tile
{
public:
	TargetTile(float rotation);
	virtual ~TargetTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
