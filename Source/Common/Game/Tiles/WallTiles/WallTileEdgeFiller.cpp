//
//  WallTileEdgeFiller.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WallTileEdgeFiller.h"
#include "../../../OpenGL/OpenGL.h"
#include "../../../Constants/Constants.h"


WallTileEdgeFiller::WallTileEdgeFiller(float rotation) : Tile(TileTypeWallEdgeFiller, RES_TILE_WALL_EDGE_FILLER, false, rotation, true)
{

}

WallTileEdgeFiller::~WallTileEdgeFiller()
{

}

int WallTileEdgeFiller::getWeight()
{
	return 10000;
}


const char* WallTileEdgeFiller::getType()
{
    return TILE_WALL_EDGE_FILLER_TYPE;
}
