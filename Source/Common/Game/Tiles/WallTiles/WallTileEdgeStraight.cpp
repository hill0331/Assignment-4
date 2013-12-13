//
//  WallTileEdgeStraight.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WallTileEdgeStraight.h"
#include "../../../OpenGL/OpenGL.h"
#include "../../../Constants/Constants.h"


WallTileEdgeStraight::WallTileEdgeStraight(float rotation) : Tile(TileTypeWallEdgeStraight, RES_TILE_WALL_EDGE_STRAIGHT, false, rotation, true)
{

}

WallTileEdgeStraight::~WallTileEdgeStraight()
{

}

int WallTileEdgeStraight::getWeight()
{
	return 10000;
}


const char* WallTileEdgeStraight::getType()
{
    return TILE_WALL_EDGE_STRAIGHT_TYPE;
}
