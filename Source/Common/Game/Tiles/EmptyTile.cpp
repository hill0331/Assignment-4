//
//  EmptyTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "EmptyTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


EmptyTile::EmptyTile(float rotation) : Tile(TileTypeEmpty, RES_TILE_BLANK, true, rotation, false)
{

}

EmptyTile::~EmptyTile()
{

}

int EmptyTile::getWeight()
{
	return 100;
}


const char* EmptyTile::getType()
{
    return TILE_EMPTY_TYPE;
}
