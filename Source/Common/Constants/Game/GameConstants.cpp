#include "GameConstants.h"


//Game Constants
const char* GAME_SCREEN_NAME = "Game";

//Tiles Constants
const char* TILE_EMPTY_TYPE = "EmptyTile";
const char* TILE_WALL_STRAIGHT_TYPE = "WallStraightTile";
const char* TILE_WALL_CORNER_90_TYPE = "WallCorner90Tile";
const char* TILE_WALL_EDGE_STRAIGHT_TYPE = "WallEdgeStraightTile";
const char* TILE_WALL_EDGE_CORNER_90_TYPE = "WallEdgeCorner90Tile";
const char* TILE_WALL_EDGE_FILLER_TYPE = "WallEdgeFillerTile";
const char* TILE_UNWALKABLE_TYPE = "UnwalkableTile";
const char* TILE_GRASS_TYPE = "GrassTile";
const char* TILE_PAVEMENT_TYPE = "PavementTile";
const char* TILE_ROCK_TYPE = "RockTile";
const char* TILE_SAND_TYPE = "SandTile";
const char* TILE_TREE_TYPE = "TreeTile";
const char* TILE_WATER_TYPE = "WaterTile";
const char* TILE_ENEMY_SPAWN_TYPE = "EnemySpawnTile";
const char* TILE_PLAYER_SPAWN_TYPE = "PlayerSpawnTile";
const char* TILE_TARGET_TYPE = "TargetTile";
const int TILE_PADDING = 2;

//Player Constants
const char* PLAYER_TYPE = "Player";
const int PLAYER_SIZE = 24;
const float PLAYER_SPEED = 150.0f;
const OpenGLColor PLAYER_INSIDE_COLOR = OpenGLColor(0.0f, 0.0f, 0.0f, 1.0f);
const OpenGLColor PLAYER_OUTLINE_COLOR = OpenGLColor(1.0f, 1.0f, 1.0f, 1.0f);

//Enemy constants
const char* ENEMY_TYPE = "Enemy";