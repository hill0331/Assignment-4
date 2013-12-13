//
//  TargetTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "TargetTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


TargetTile::TargetTile(float rotation) : Tile(TileTypeTarget, RES_TILE_TARGET, true, rotation, false)
{

}

TargetTile::~TargetTile()
{

}

int TargetTile::getWeight()
{
	return 1;
}


const char* TargetTile::getType()
{
    return TILE_TARGET_TYPE;
}
