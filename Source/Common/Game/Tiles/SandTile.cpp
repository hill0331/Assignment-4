#include "SandTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


SandTile::SandTile(float rotation) : Tile(TileTypeSand, RES_TILE_SAND, true, rotation, false)
{

}

SandTile::~SandTile()
{

}

int SandTile::getWeight()
{
	return 6;
}

const char* SandTile::getType()
{
    return TILE_SAND_TYPE;
}
