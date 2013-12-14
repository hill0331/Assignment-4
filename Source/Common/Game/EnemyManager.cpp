#include "EnemyManager.h"

#include <stdlib.h> 
#include <time.h>  
#include "SpawnPoint.h"
#include "EnemyUnit.h"

EnemyManager::EnemyManager(Level * level) :
m_Level(NULL),
m_TargetTile(NULL),
m_ElapsedTime(45),
m_WaveNumber(0),
m_WaveInitialEnemyCount(5),
m_EnemiesToSpawn(0),
m_WaveTime(60),
m_WaveCountMutiplier(1.2f),
m_WaveSpeedMultiplier(0)
{
	m_Level = level;
	srand(time(NULL));
}

EnemyManager::~EnemyManager()
{	
	for (int i = 0; i < m_Units.size(); i++)
	{
		Unit * unit = m_Units.at(i);
		delete unit;
		unit = NULL;
	}
	m_Units.clear();

	for (int i = 0; i < m_EnemySpawnPoints.size(); i++)
	{
		SpawnPoint * spawnPoint = m_EnemySpawnPoints.at(i);
		delete spawnPoint;
		spawnPoint = NULL;
	}
	m_EnemySpawnPoints.clear();
}

void EnemyManager::update(double delta)
{
	enemyWaveControl(delta);

	//Update spawn Points
	if (m_EnemySpawnPoints.empty() == false)
	{
		for (int i = 0; i < m_EnemySpawnPoints.size(); i++)
		{
			m_EnemySpawnPoints.at(i)->update(delta);
		}
	}

	if (m_Queue.empty() == false)
	{
		Unit *unit = m_Queue.top();
		m_Queue.pop();
		unit->setState(START);
	}

	for (int i = 0; i < m_Units.size(); i++)
	{
		if (m_Units.at(i)->getIsActive() == false)
		{			
			Unit * unit = m_Units.at(i);
			delete unit;
			unit = NULL;
			m_Units.erase(m_Units.begin() + i);
		}
		else
		{
			m_Units.at(i)->update(delta);
		}
	}
}

void EnemyManager::paint()
{
	//Paint enemy units
	for (int i = 0; i < m_Units.size(); i++)
	{
		m_Units.at(i)->paint();
	}
}

void EnemyManager::reset()
{
	for (int i = 0; i < m_Units.size(); i++)
	{
		Unit * unit = m_Units.at(i);
		delete unit;
		unit = NULL;
	}
	m_Units.clear();

	for (int i = 0; i < m_EnemySpawnPoints.size(); i++)
	{
		SpawnPoint * spawnPoint = m_EnemySpawnPoints.at(i);
		delete spawnPoint;
		spawnPoint = NULL;
	}
	m_EnemySpawnPoints.clear();
}

void EnemyManager::enemyWaveControl(double delta)
{
	//Reseed pseudo-random number generator
	srand(time(NULL));

	//Update elapsed time
	m_ElapsedTime += delta;

	if (m_ElapsedTime > m_WaveTime)
	{
		m_ElapsedTime = 0;
		m_WaveNumber ++;
		m_EnemiesToSpawn = (int)(m_WaveInitialEnemyCount * (m_WaveCountMutiplier*m_WaveNumber));

		while (m_EnemiesToSpawn != 0)
		{
			int randomSpawn = rand() % (m_EnemySpawnPoints.size());

			int enemiesToDelegate = rand() % m_EnemiesToSpawn +1;
			m_EnemiesToSpawn -= enemiesToDelegate;

			m_EnemySpawnPoints.at(randomSpawn)->SpawnUnits(enemiesToDelegate);

		}
	}
}

void EnemyManager::addSpawnPointAtTile(Tile * tile)
{	
	static int spawnTime = 5;

	SpawnPoint * enemySpawn = new SpawnPoint(m_Level, this);
	enemySpawn->setSpawnRate(spawnTime);
	enemySpawn->setCurrentTile(tile);

	//spawnTime++;

	m_EnemySpawnPoints.push_back(enemySpawn);
}

void EnemyManager::queueForPathFinding(Unit * unit)
{
	unit->setState(STATIONARY);
	m_Queue.push(unit);
}

void EnemyManager::addEnemyUnit(Unit *unit)
{
	m_Units.push_back(unit);
	unit->setDestinationTile(m_TargetTile);
}

Tile * EnemyManager::getTargetTile()
{
	return m_TargetTile;
}

void EnemyManager::setTargetTile(Tile * tile)
{
	m_TargetTile = tile;
}

