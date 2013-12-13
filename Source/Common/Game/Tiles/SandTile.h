#ifndef SAND_TILE_H
#define SAND_TILE_H

#include "Tile.h"


class SandTile : public Tile
{
public:
	SandTile(float rotation);
	virtual ~SandTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
