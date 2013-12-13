
#ifndef LEVEL_CONSTANTS_H
#define LEVEL_CONSTANTS_H

//Global enum for the Level's tile types,
//add additional tile types in this enum
enum TileType
{
	TileTypeEmpty,
	TileTypeWallStraight,
	TileTypeWallCorner90,
	TileTypeWallEdgeStraight,
	TileTypeWallEdgeCorner90,
	TileTypeWallEdgeFiller,
	TileTypeUnwalkable,
	TileTypeGrass,
	TileTypePavement,
	TileTypeRock,
	TileTypeSand,
	TileTypeWater,
	TileTypeTree,
	TileTypeEnemySpawn,
	TileTypePlayerSpawn,
	TileTypeTarget,
	TileTypeUnknown,
	TileTypeCount
};

//Level editor screen name
extern const char* LEVEL_EDITOR_SCREEN_NAME;

//Empty Level Constants
extern const int EMPTY_LEVEL_TILE_SIZE;
extern const int EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX;

#endif