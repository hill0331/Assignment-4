//
//  PlayerSpawnTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "PlayerSpawnTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


PlayerSpawnTile::PlayerSpawnTile(float rotation) : Tile(TileTypePlayerSpawn, RES_TILE_PLAYER_SPAWN, true, rotation, false)
{

}

PlayerSpawnTile::~PlayerSpawnTile()
{

}

int PlayerSpawnTile::getWeight()
{
	return 0;
}


const char* PlayerSpawnTile::getType()
{
    return TILE_PLAYER_SPAWN_TYPE;
}
