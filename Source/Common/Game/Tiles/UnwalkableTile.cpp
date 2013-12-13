//
//  UnwalkableTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "UnwalkableTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


UnwalkableTile::UnwalkableTile(float rotation) : Tile(TileTypeUnwalkable, RES_TILE_UNWALKABLE, false, rotation, false)
{

}

UnwalkableTile::~UnwalkableTile()
{

}

int UnwalkableTile::getWeight()
{
	return 10000;
}


const char* UnwalkableTile::getType()
{
    return TILE_EMPTY_TYPE;
}
