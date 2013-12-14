#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include <vector>
#include <queue>
#include "Unit.h"

class Level;
class Unit;
class SpawnPoint;
class Tile;

struct mycomparison 
{	
	bool operator() (Unit* &lhs, Unit* &rhs) const
	{
		// assume Unit has a getScore method that tells us 
		// how important this Unit is.
		return lhs->getScore() < rhs->getScore();
	}
};

typedef std::priority_queue<Unit *, std::vector<Unit *>, mycomparison> mypq_type;

class EnemyManager
{
public:
	EnemyManager(Level * level);
	~EnemyManager();

	//Game lifecycle methods
	void update(double delta);
	void paint();
	void reset();

	Level* getLevel();
	void setLevel(Level* level);

	void addSpawnPointAtTile(Tile * tile);
	void queueForPathFinding(Unit * unit);
	void addEnemyUnit(Unit *unit);

	Tile * getTargetTile();
	void setTargetTile(Tile * tile);

	std::vector<SpawnPoint*> getSpawnPoints();

private:
	void enemyWaveControl(double delta);

	std::vector<Unit*> m_Units;
	std::vector<SpawnPoint*> m_EnemySpawnPoints;

	double m_ElapsedTime;
	float m_WaveTime;
	int m_WaveNumber;
	float m_WaveCountMutiplier;
	float m_WaveSpeedMultiplier;
	int m_WaveInitialEnemyCount;
	int m_EnemiesToSpawn;
	mypq_type m_Queue;
	Level * m_Level;
	Tile * m_TargetTile;
};

#endif