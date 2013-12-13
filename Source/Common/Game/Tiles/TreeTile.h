#ifndef TREE_TILE_H
#define TREE_TILE_H

#include "Tile.h"


class TreeTile : public Tile
{
public:
	TreeTile(float rotation);
	virtual ~TreeTile();

	int getWeight();
  
    //Return the type of the tile
    const char* getType();
};

#endif
