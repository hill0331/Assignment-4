//
//  EnemySpawnTile.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "EnemySpawnTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


EnemySpawnTile::EnemySpawnTile(float rotation) : Tile(TileTypeEnemySpawn, RES_TILE_ENEMY_SPAWN, true, rotation, false)
{

}

EnemySpawnTile::~EnemySpawnTile()
{

}

int EnemySpawnTile::getWeight()
{
	return 0;
}


const char* EnemySpawnTile::getType()
{
    return TILE_ENEMY_SPAWN_TYPE;
}
