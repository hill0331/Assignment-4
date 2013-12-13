#ifndef WATER_TILE_H
#define WATER_TILE_H

#include "Tile.h"


class WaterTile : public Tile
{
public:
	WaterTile(float rotation);
	virtual ~WaterTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
