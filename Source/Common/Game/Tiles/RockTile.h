#ifndef ROCK_TILE_H
#define ROCK_TILE_H

#include "Tile.h"


class RockTile : public Tile
{
public:
	RockTile(float rotation);
	virtual ~RockTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
