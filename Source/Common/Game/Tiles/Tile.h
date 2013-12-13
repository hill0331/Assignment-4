#ifndef TILE_H
#define TILE_H

#include "../GameObject.h"
#include "../../Constants/Constants.h"
#include <stdlib.h>


class OpenGLTexture;

class Tile : public GameObject
{
public:
    //Tile takes on parameter, whether it can be walked on or not
	Tile(TileType tileType, const char* tileTexture, bool isWalkableTile, float tileRotation, bool isVisibleInGame);
	virtual ~Tile();
    
    //Update, Paint and reset methods
	virtual void update(double delta);
	virtual void paint();
    virtual void reset();
    
    //Paint methods to draw the tile score, drawn from the PathFinding class
    virtual void paintScoreG(int scoreG);
    virtual void paintScoreH(int scoreH);
    virtual void paintScoreF(int scoreF);
    
    //Paint method to draw the tile's index, drawn from the Level class
    virtual void paintIndex(int index);
    
    //Pure virtual method inerited from GameObject
    virtual const char* getType() = 0;
    virtual int getWeight() = 0;
    //
    virtual TileType getTileType();
    
    //Is this a walkable tile, can the user walk on the tile
    virtual bool isWalkableTile();
    
    //Sets wether the tile is selected or not
    virtual void setIsSelected(bool isSelected);
	virtual bool isSelected();
    
    //Sets wether the tile is a path or not
	virtual void setIsPath(bool isPath);
	virtual bool isPath();

	//Get and set rotation of texture
	float getTileRotation();
	void setTileRotation(float rotation);

	//Get and set the bool to determine if the texture is drawn in game
	bool getIsVisibleInGame();
	void setIsVisibleInGame(bool isVisible);
    
protected:
    //Conveniance method to paint a score number and a certain position
    void paintScoreNumber(int number, float x, float y);
    
    //Member variables
    TileType m_TileType;
    bool m_IsWalkableTile;
    bool m_IsSelected;
	bool m_IsPath;
    OpenGLTexture* m_SelectedTile;
    OpenGLTexture** m_TileIndexNumbers;
    OpenGLTexture** m_TileScoreNumbers;
	float m_Rotation;
	bool m_IsVisibleInGame;
};

#endif
