//
//  WallTileStraight.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WallTileStraight.h"
#include "../../../OpenGL/OpenGL.h"
#include "../../../Constants/Constants.h"


WallTileStraight::WallTileStraight(float rotation) : Tile(TileTypeWallStraight, RES_TILE_WALL_STRAIGHT, false, rotation, true)
{

}

WallTileStraight::~WallTileStraight()
{

}

int WallTileStraight::getWeight()
{
	return 10000;
}


const char* WallTileStraight::getType()
{
	return TILE_WALL_STRAIGHT_TYPE;
}
