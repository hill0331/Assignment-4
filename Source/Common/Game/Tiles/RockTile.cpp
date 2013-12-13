#include "RockTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


RockTile::RockTile(float rotation) : Tile(TileTypeRock, RES_TILE_ROCK, true, rotation, false)
{

}

RockTile::~RockTile()
{

}

int RockTile::getWeight()
{
	return 10;
}


const char* RockTile::getType()
{
    return TILE_ROCK_TYPE;
}
