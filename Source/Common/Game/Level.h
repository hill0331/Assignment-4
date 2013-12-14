//
//  Level.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
// Modified by Dan Lingman on 2013-11-09
// added clear method
//

#ifndef LEVEL_H
#define LEVEL_H

#include "../Constants/Constants.h"
#include "../Path/FastPathFinder.h"
#include <vector>

class Tile;
class Player;
class EnemyManager;
class OpenGLTexture;

class Level
{
public:
	Level(bool isEditingLevel = false);
	~Level();
    
	//Update, paint and reset methods
	void update(double delta);
    void paint();
    void reset();
    
    //
	void load(std::string levelName);
	

    //Input methods
    void mouseLeftClickUpEvent(float positionX, float positionY);
    void keyUpEvent(int keyCode);
	void clear();
	//
    TileType getTileTypeForIndex(int index);
    
	//Tile count methods
    unsigned int getNumberOfTiles();
	unsigned int getNumberOfHorizontalTiles();
	unsigned int getNumberOfVerticalTiles();
    
	//Validate that the tile coordinates passed in are valid
	bool validateTileCoordinates(int coordinatesX, int coordinatesY);
    
	//Converts a position in screen space into a position in coordinate space
	int getTileCoordinateForPosition(int position);
    

	//Index methods
	int getTileIndexForPosition(int positionX, int positionY);
	int getTileIndexForCoordinates(int coordinatesX, int coordinatesY);
	int getTileIndexForTile(Tile* tile);
    
	//Tile methods
	Tile* getTileForPosition(int positionX, int positionY);
	Tile* getTileForCoordinates(int coordinatesX, int coordinatesY);
	Tile* getTileForIndex(int index);
    
    //
	void setTileTypeAtPosition(TileType tileType, int positionX, int positionY, float tileRotation);
	void setTileTypeAtCoordinates(TileType tileType, int coordinatesX, int coordinatesY, float tileRotation);
	void setTileTypeAtIndex(TileType tileType, int index, float tileRotation);
    
    //Coveniance methods to toggle debug paint methods
    void togglePaintTileScoring();
    void togglePaintTileIndexes();		

	//Lives
	int getNumberOfLives();
	void setNumberOfLives(int lives);
	void decrementLives(int livesToSubract);

	//Score
	int getPlayerScore();
	void setPlayerScore(int score);
	void addToPlayerScore(int pointsToAdd);

protected:
	//Disables the old tiles selection (if ground tile) and
	//enables the newly selected tiles selection (if ground tile)
	void setSelectedTileIndex(int selectedIndex);

	void gameOver();
    
	//Protected Member variables
	Player* m_Player;
	Tile** m_Tiles;
	EnemyManager * m_EnemyManager;

	unsigned int m_HorizontalTiles;
	unsigned int m_VerticalTiles;
	unsigned int m_TileSize;
    unsigned int m_PlayerStartingTileIndex;
	int m_SelectedTileIndex;
    bool m_PaintTileScoring;
	bool m_PaintBradPathScoring;
    bool m_PaintTileIndexes;

	OpenGLTexture * m_LevelBkg;
	Tile * m_TargetTile;

	int m_Lives;
	int m_PlayerScore;

};


#endif
