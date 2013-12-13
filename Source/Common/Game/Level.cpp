//
//  Level.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
// Modified by Dan Lingman on 2013-11-09
// added support for additonal tiles types
// added clear method
//

#include "Level.h"
#include "Player.h"
#include "../OpenGL/OpenGL.h"

//Tiles
#include "Tiles/Tile.h"
#include "Tiles/EmptyTile.h"
#include "Tiles/WallTiles/WallTileStraight.h"
#include "Tiles/WallTiles/WallTileCorner90.h"
#include "Tiles/WallTiles/WallTileEdgeStraight.h"
#include "Tiles/WallTiles/WallTileEdgeCorner90.h"
#include "Tiles/WallTiles/WallTileEdgeFiller.h"
#include "Tiles/UnwalkableTile.h"
#include "Tiles/GrassTile.h"
#include "Tiles/PavementTile.h"
#include "Tiles/RockTile.h"
#include "Tiles/SandTile.h"
#include "Tiles/TreeTile.h"
#include "Tiles/WaterTile.h"
#include "Tiles/EnemySpawnTile.h"
#include "Tiles/PlayerSpawnTile.h"
#include "Tiles/TargetTile.h"

#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include <stdlib.h>
#include <fstream>
#include "../Libraries/jsoncpp/json.h"
#include "../Path/FastPathFinder.h"
#include "EnemyUnit.h"

Level::Level(bool isEditingLevel) :
m_HorizontalTiles(0),
m_VerticalTiles(0),
m_TileSize(EMPTY_LEVEL_TILE_SIZE),
m_PlayerStartingTileIndex(768 / 2 + 16), // EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX),
m_Player(NULL),
m_Tiles(NULL),
m_SelectedTileIndex(-1),
m_PaintTileScoring(false),
m_PaintTileIndexes(false),
m_PaintBradPathScoring(false),
m_LevelBkg(NULL),
m_TargetTile(NULL),
m_Lives(3)
{
	//Create the player object
	if (isEditingLevel == false || true)
	{
		//m_Player = new Player(this);
	}	
	
}

Level::~Level()
{
	//Delete the player object
	if (m_Player != NULL)
	{
		delete m_Player;
		m_Player = NULL;
	}

	//Delete the tiles array, the inheriting class
	//must delete the object in this array itself
	if (m_Tiles != NULL)
	{
		//Cycle through and delete all the tile objects in the array
		for (int i = 0; i < (int)getNumberOfTiles(); i++)
		{
			if (m_Tiles[i] != NULL)
			{
				delete m_Tiles[i];
				m_Tiles[i] = NULL;
			}
		}

		delete[] m_Tiles;
		m_Tiles = NULL;
	}

	m_EnemySpawnPoints.clear();	
}

void Level::clear()
{

	for (int i = 0; i < (int)getNumberOfTiles(); i++)
	{
		if (m_Tiles[i] != NULL)
		{
			setTileTypeAtIndex(TileTypeEmpty, i, 0.0f);
		}
	}
}
Tile * Level::getTargetTile()
{
	return m_TargetTile;
}

void Level::update(double aDelta)
{
	if (m_Lives <= 0)
	{
		gameOver();
	}
	//Update all the game tiles
	for (int i = 0; i < (int)getNumberOfTiles(); i++)
	{
		if (m_Tiles[i] != NULL)
		{
			m_Tiles[i]->update(aDelta);
		}
	}

	if (m_Queue.empty() == false)
	{
		Unit *unit = m_Queue.top();
		m_Queue.pop();
		unit->setState(START);
	}

	//Update the Player
	if (m_Player != NULL)
	{
		m_Player->update(aDelta);

	}

	//Update spawn Points
	if (m_EnemySpawnPoints.size() != 0)
	{
		for (int i = 0; i < m_EnemySpawnPoints.size(); i++)
		{			
			m_EnemySpawnPoints.at(i)->update(aDelta);
		}
	}

	for (int i = 0; i < m_Units.size(); i++)
	{
		if (m_Units.at(i)->getIsActive() == false)
		{
			//m_Units.at(i)->deleteRequested(true);	
			//m_Units.at(i)->update(aDelta);
			Unit * unit = m_Units.at(i);
			delete unit;
			unit = NULL;
			m_Units.erase(m_Units.begin() + i);
		}
		else
		{
			m_Units.at(i)->update(aDelta);
		}
	}

}

void Level::paint()
{
	//Paint the background
	OpenGLRenderer::getInstance()->drawTexture(m_LevelBkg, 0.0f, 0.0f);

	//Cycle through and paint all the tiles
	for (int i = 0; i < (int)getNumberOfTiles(); i++)
	{
		//Safety check the tile
		if (m_Tiles[i] != NULL)
		{
			//If tile should be visible
			if (m_Tiles[i]->getIsVisibleInGame() == true)
			{
				//Paint the tile
				m_Tiles[i]->paint();
			}			
		}
	}


	//Paint the Player
	if (m_Player != NULL)
	{		
		//Paint the player
		m_Player->paint();
	}

	//Paint enemy units
	for (int i = 0; i < m_Units.size(); i++)
	{
		m_Units.at(i)->paint();		
	}	
}


void Level::reset()
{
	if (m_Tiles != NULL)
	{
		//Cycle through and reset all the tiles
		for (int i = 0; i < (int)getNumberOfTiles(); i++)
		{
			if (m_Tiles[i] != NULL)
			{
				m_Tiles[i]->reset();
			}
		}

		//Reset the Player
		if (m_Player != NULL)
		{
			m_Player->reset();
			m_Player->setCurrentTile(m_Tiles[m_PlayerStartingTileIndex]);
		}

		for (int i = 0; i < m_Units.size(); i++)
		{
			Unit* unit = (Unit*)(m_Units.at(i));
			unit->deleteRequested(true);
		}
		m_Units.clear();
		//m_SpawnPoint->setCurrentTile(m_Tiles[0]);
	}
}


void Level::mouseLeftClickUpEvent(float aPositionX, float aPositionY)
{
	//Convert the mouse click position, into a tile index
	int index = getTileIndexForPosition((int)aPositionX, (int)aPositionY);

	//Safety check that the tile isn't NULL
	if (m_Tiles[index] != NULL)
	{
		//Set the selected tile index
		setSelectedTileIndex(index);

		//If the tile is walkable, set the player's destination tile
		if (m_Tiles[index]->isWalkableTile() == true)
		{
			if (m_Player != NULL)
			{
				m_Player->setDestinationTile(m_Tiles[m_SelectedTileIndex]);
			}
		}
	}
}

void Level::keyUpEvent(int keyCode)
{
	
}

void Level::load(std::string levelName)
{
	//If the level name isn't NULL load the level from the filesystem,
	//if it is NULL load an empty level with just ground tiles
	if (levelName != "")
	{
		Json::Value root;
		Json::Reader reader;
		std::ifstream in;		

		std::string bkgLevelName = "backgrounds/";
		bkgLevelName.append(levelName);

		//Load background image
		if (m_LevelBkg != NULL)
		{
			delete m_LevelBkg;
			m_LevelBkg = NULL;
		}

		m_LevelBkg = new OpenGLTexture(bkgLevelName.c_str());

		levelName.append(".json");

		in.open(levelName);

		bool success = reader.parse(in, root, false);
		

		if (success == true)
		{
			int width = root.get("width", NULL).asInt();
			int height = root.get("height", NULL).asInt();

			if (width != NULL)
			{
				m_HorizontalTiles = width;
			}

			if (height != NULL)
			{
				m_VerticalTiles = height;
			}

			m_Tiles = new Tile*[m_HorizontalTiles * m_VerticalTiles];

			//Initialize all the tiles to NULL
			for (int i = 0; i < (int)(m_HorizontalTiles * m_VerticalTiles); i++)
			{
				m_Tiles[i] = NULL;
			}

			const Json::Value tiles = root["tiles"];

			//Tile variables
			int tileIndex = 0;
			float tileX = 0.0f;
			float tileY = 0.0f;

			//Cycle through all the tiles and create them
			for (int v = 0; v < getNumberOfVerticalTiles(); v++)
			{
				for (int h = 0; h < getNumberOfHorizontalTiles(); h++)
				{
					//Delete the tile at the index, if one exists
					if (m_Tiles[tileIndex] != NULL)
					{
						delete m_Tiles[tileIndex];
						m_Tiles[tileIndex] = NULL;
					}

					//Deterime tile type to add
					int tileType = tiles[tileIndex].get("type", NULL).asInt();
					setTileTypeAtIndex((TileType)tileType, tileIndex, tiles[tileIndex].get("rotation", NULL).asInt());

					if (m_Tiles[tileIndex]->getTileType() == TileTypeEnemySpawn)
					{
						static int spawnTime = 2;

						SpawnPoint * enemySpawn = new SpawnPoint(this);
						enemySpawn->setSpawnRate(spawnTime);
						enemySpawn->setCurrentTile(m_Tiles[tileIndex]);

						m_EnemySpawnPoints.push_back(enemySpawn);
						spawnTime += 1;						
					}
					else if (m_Tiles[tileIndex]->getTileType() == TileTypeTarget)
					{
						m_TargetTile = m_Tiles[tileIndex];
					}

					//Increment the tile index
					tileIndex++;

					//And increment the tile x position
					tileX += m_TileSize;
				}

				//Increment the tile y position and reset the tile x position, since we started a new row
				tileY += m_TileSize;
				tileX = 0.0f;
			}

			//The level is loaded, reset everything
			reset();
		}
		else
		{
			MessageBox(0, "Level Loading Failed", "Error", MB_OK);
			in.close();
			exit(0);
		}
		in.close();			
	}	
}


TileType Level::getTileTypeForIndex(int index)
{
	if (index >= 0 && index < (int)getNumberOfTiles())
	{
		return m_Tiles[index]->getTileType();
	}
	return TileTypeUnknown;
}

unsigned int Level::getNumberOfTiles()
{
	return getNumberOfHorizontalTiles() * getNumberOfVerticalTiles();
}

unsigned int Level::getNumberOfHorizontalTiles()
{
	return m_HorizontalTiles;
}

unsigned int Level::getNumberOfVerticalTiles()
{
	return m_VerticalTiles;
}

bool Level::validateTileCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	if (aCoordinatesX < -2 || aCoordinatesY < -2 || aCoordinatesX >= (int)getNumberOfHorizontalTiles() || aCoordinatesY >= (int)getNumberOfVerticalTiles())
	{
		return false;
	}
	return true;
}

int Level::getTileCoordinateForPosition(int aPosition)
{
	return (aPosition / m_TileSize) + 1;
}

int Level::getTileIndexForPosition(int aPositionX, int aPositionY)
{
	int coordinatesX = getTileCoordinateForPosition(aPositionX);
	int coordinatesY = getTileCoordinateForPosition(aPositionY);
	return getTileIndexForCoordinates(coordinatesX, coordinatesY);
}

int Level::getTileIndexForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	//Validate the coordinates, then calculate the array index
	if (validateTileCoordinates(aCoordinatesX, aCoordinatesY) == true)
	{
		return (aCoordinatesX + (aCoordinatesY * getNumberOfHorizontalTiles()));
	}

	return -1;
}

int Level::getTileIndexForTile(Tile* aTile)
{
	return getTileIndexForPosition((int)(aTile->getX()), (int)(aTile->getY()));
}

Tile* Level::getTileForPosition(int aPositionX, int aPositionY)
{
	return getTileForIndex(getTileIndexForPosition(aPositionX, aPositionY));
}

Tile* Level::getTileForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	return getTileForIndex(getTileIndexForCoordinates(aCoordinatesX, aCoordinatesY));
}

Tile* Level::getTileForIndex(int aIndex)
{
	//Safety check the index bounds
	if (aIndex >= 0 && aIndex < (int)getNumberOfTiles())
	{
		return m_Tiles[aIndex];
	}

	//If we got here, it means the index passed in was out of bounds
	return NULL;
}

void Level::setTileTypeAtPosition(TileType tileType, int positionX, int positionY, float tileRotation)
{
	setTileTypeAtIndex(tileType, getTileIndexForPosition(positionX, positionY), tileRotation);
}

void Level::setTileTypeAtCoordinates(TileType tileType, int coordinatesX, int coordinatesY, float tileRotation)
{
	setTileTypeAtIndex(tileType, getTileIndexForCoordinates(coordinatesX, coordinatesY), tileRotation);
}

void Level::setTileTypeAtIndex(TileType tileType, int index, float tileRotation)
{
	//Safety check the index
	if (index >= 0 && index < getNumberOfTiles())
	{
		//Don't replace the tile if its the same type of tile that already exists
		if (m_Tiles[index] != NULL && m_Tiles[index]->getTileType() == tileType)
		{
			//Set the rotation though
			m_Tiles[index]->setTileRotation(tileRotation);
			return;
		}

		//Delete the tile at the index, if one exists
		if (m_Tiles[index] != NULL)
		{
			delete m_Tiles[index];
			m_Tiles[index] = NULL;
		}

		//Create the new tile based on the TileType
		switch (tileType)
		{
		case TileTypeEmpty:
			m_Tiles[index] = new EmptyTile(tileRotation);
			break;

		case TileTypeWallStraight:
			m_Tiles[index] = new WallTileStraight(tileRotation);
			break;

		case TileTypeWallCorner90:
			m_Tiles[index] = new WallTileCorner90(tileRotation);
			break;

		case TileTypeWallEdgeStraight:
			m_Tiles[index] = new WallTileEdgeStraight(tileRotation);
			break;

		case TileTypeWallEdgeCorner90:
			m_Tiles[index] = new WallTileEdgeCorner90(tileRotation);
			break;

		case TileTypeWallEdgeFiller:
			m_Tiles[index] = new WallTileEdgeFiller(tileRotation);
			break;

		case TileTypeUnwalkable:
			m_Tiles[index] = new UnwalkableTile(tileRotation);
			break;

		case TileTypeGrass:
			m_Tiles[index] = new GrassTile(tileRotation);
			break;

		case TileTypePavement:
			m_Tiles[index] = new PavementTile(tileRotation);
			break;

		case TileTypeRock:
			m_Tiles[index] = new RockTile(tileRotation);
			break;

		case TileTypeSand:
			m_Tiles[index] = new SandTile(tileRotation);
			break;

		case TileTypeTree:
			m_Tiles[index] = new TreeTile(tileRotation);
			break;

		case TileTypeWater:
			m_Tiles[index] = new WaterTile(tileRotation);
			break;

		case TileTypeEnemySpawn:
			m_Tiles[index] = new EnemySpawnTile(tileRotation);
			break;

		case TileTypePlayerSpawn:
			m_Tiles[index] = new PlayerSpawnTile(tileRotation);
			break;

		case TileTypeTarget:
			m_Tiles[index] = new TargetTile(tileRotation);
			break;

		default:
			m_Tiles[index] = new EmptyTile(tileRotation);
			break;
		}

		//Calculate the coordinates and set the tile position and size
		int coordinateX = (index % getNumberOfHorizontalTiles());
		int coordinateY = ((index - coordinateX) / getNumberOfHorizontalTiles());
		m_Tiles[index]->setPosition((coordinateX  * m_TileSize) - m_TileSize, (coordinateY * m_TileSize) - m_TileSize);
		m_Tiles[index]->setSize(m_TileSize, m_TileSize);
	}
}

void Level::togglePaintTileScoring()
{
	m_PaintTileScoring = !m_PaintTileScoring;
}

void Level::togglePaintTileIndexes()
{
	m_PaintTileIndexes = !m_PaintTileIndexes;
}

void Level::setSelectedTileIndex(int aSelectedIndex)
{
	//Deselect the previously selected tile
	if (m_SelectedTileIndex >= 0 && m_SelectedTileIndex < (int)getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(false);
	}

	//Set the new tile index
	m_SelectedTileIndex = aSelectedIndex;

	//Selected the newly selected tile
	if (m_SelectedTileIndex >= 0 && m_SelectedTileIndex < (int)getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(true);
	}
}

void Level::queueForPathFinding(Unit * unit)
{
	unit->setState(STATIONARY);
	m_Queue.push(unit);
}

void Level::addEnemyUnit(Unit *unit)
{
	m_Units.push_back(unit);
	unit->setDestinationTile(m_TargetTile);
	queueForPathFinding(unit);
}

int Level::getNumberOfLives()
{
	return m_Lives;
}


void Level::setNumberOfLives(int lives)
{
	m_Lives = lives;
}

void Level::decrementLives(int livesToSubract)
{
	m_Lives -= livesToSubract;
}

void Level::gameOver()
{
	ScreenManager::getInstance()->switchScreen(GAME_OVER_SCREEN_NAME);
}
