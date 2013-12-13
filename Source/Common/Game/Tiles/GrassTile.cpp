#include "GrassTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


GrassTile::GrassTile(float rotation) : Tile(TileTypeGrass, RES_TILE_GRASS, true, rotation, false)
{

}

GrassTile::~GrassTile()
{

}

int GrassTile::getWeight()
{
	return 4;
}

const char* GrassTile::getType()
{
    return TILE_GRASS_TYPE;
}
