//
//  WallTileCorner90.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WallTileCorner90.h"
#include "../../../OpenGL/OpenGL.h"
#include "../../../Constants/Constants.h"


WallTileCorner90::WallTileCorner90(float rotation) : Tile(TileTypeWallCorner90, RES_TILE_WALL_CORNER_90, false, rotation, true)
{

}

WallTileCorner90::~WallTileCorner90()
{

}

int WallTileCorner90::getWeight()
{
	return 10000;
}


const char* WallTileCorner90::getType()
{
	return TILE_WALL_CORNER_90_TYPE;
}
