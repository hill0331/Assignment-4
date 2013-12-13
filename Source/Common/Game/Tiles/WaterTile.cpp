#include "WaterTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


WaterTile::WaterTile(float rotation) : Tile(TileTypeWater, RES_TILE_WATER, true, rotation, false)
{

}

WaterTile::~WaterTile()
{

}

int WaterTile::getWeight()
{
	return 50;
}

const char* WaterTile::getType()
{
    return TILE_WATER_TYPE;
}
