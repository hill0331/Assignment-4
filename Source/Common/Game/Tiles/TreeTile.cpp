#include "TreeTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


TreeTile::TreeTile(float rotation) : Tile(TileTypeTree, RES_TILE_TREE, true, rotation, false)
{

}

TreeTile::~TreeTile()
{

}

int TreeTile::getWeight()
{
	return 40;
}

const char* TreeTile::getType()
{
    return TILE_TREE_TYPE;
}
