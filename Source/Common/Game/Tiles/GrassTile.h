#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include "Tile.h"


class GrassTile : public Tile
{
public:
	GrassTile(float rotation);
	virtual ~GrassTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
