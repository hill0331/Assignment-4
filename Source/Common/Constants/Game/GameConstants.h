#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "../../OpenGL/OpenGLColor.h"

//Game Constants
extern const char* GAME_SCREEN_NAME;

//Tile Constants
extern const char* TILE_EMPTY_TYPE;
extern const char* TILE_WALL_STRAIGHT_TYPE;
extern const char* TILE_WALL_CORNER_90_TYPE;
extern const char* TILE_WALL_EDGE_STRAIGHT_TYPE;
extern const char* TILE_WALL_EDGE_CORNER_90_TYPE;
extern const char* TILE_WALL_EDGE_FILLER_TYPE;
extern const char* TILE_UNWALKABLE_TYPE;
extern const char* TILE_GRASS_TYPE;
extern const char* TILE_PAVEMENT_TYPE;
extern const char* TILE_ROCK_TYPE;
extern const char* TILE_SAND_TYPE;
extern const char* TILE_TREE_TYPE;
extern const char* TILE_WATER_TYPE;
extern const char* TILE_ENEMY_SPAWN_TYPE;
extern const char* TILE_PLAYER_SPAWN_TYPE;
extern const char* TILE_TARGET_TYPE;
extern const int TILE_PADDING;

//Player Constants
extern const char* PLAYER_TYPE;
extern const int PLAYER_SIZE;
extern const float PLAYER_SPEED;
extern const OpenGLColor PLAYER_INSIDE_COLOR;
extern const OpenGLColor PLAYER_OUTLINE_COLOR;

//Enemy constants
extern const char* ENEMY_TYPE;

#endif 