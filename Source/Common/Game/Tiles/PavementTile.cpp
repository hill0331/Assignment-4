//
//  PavementTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "PavementTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


PavementTile::PavementTile(float rotation) : Tile(TileTypePavement, RES_TILE_PAVEMENT, true, rotation, false)
{

}

PavementTile::~PavementTile()
{

}

int PavementTile::getWeight()
{
	return 5;
}


const char* PavementTile::getType()
{
    return TILE_PAVEMENT_TYPE;
}
