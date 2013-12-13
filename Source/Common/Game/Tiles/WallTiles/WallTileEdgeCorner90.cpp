//
//  WallTileEdgeCorner90.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WallTileEdgeCorner90.h"
#include "../../../OpenGL/OpenGL.h"
#include "../../../Constants/Constants.h"


WallTileEdgeCorner90::WallTileEdgeCorner90(float rotation) : Tile(TileTypeWallEdgeCorner90, RES_TILE_WALL_EDGE_CORNER_90, false, rotation, true)
{

}

WallTileEdgeCorner90::~WallTileEdgeCorner90()
{

}

int WallTileEdgeCorner90::getWeight()
{
	return 10000;
}


const char* WallTileEdgeCorner90::getType()
{
    return TILE_WALL_EDGE_CORNER_90_TYPE;
}
