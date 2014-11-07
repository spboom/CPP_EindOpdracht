//
#include <tchar.h>
#include <strsafe.h>
#include <vector>
#include "tinyxml2.h"

//
#include "MainFactory.h"
#include "../Model/Location/Directions.h"
#include "../Model/Location/Staircase.h"
#include "../Model/GameObject.h"
#include "../Controller/Controller.h"
#include "../Factory/LocationFactory.h"
#include "../Factory/ItemFactory.h"
#include "../Factory/CharacterFactory.h"

//
using namespace std;
using namespace tinyxml2;

MainFactory* MainFactory::s_pInstance;

MainFactory::MainFactory()
{
	dre = default_random_engine(dev());
	chance = uniform_int_distribution<int>(0, 100);
	characteristics = new vector<string>();
}

MainFactory::~MainFactory()
{
	delete characteristics;
}

void MainFactory::fillRoom(Room* room)
{
	TheLocationFactory::Instance()->fillRoom(room);
	TheCharacterFactory::Instance()->fillRoom(room);
	//TheItemFactory::Instance()->fillRoom(room);
}

string MainFactory::getRandomVectorItems(vector<string> *random)
{
	std::vector<string>::iterator randIt = random->begin();
	std::advance(randIt, std::rand() % random->size());
	//std::cout << "Random selection: " << *randIt << std::endl;
	return *randIt;
}

int MainFactory::moveOneToGoal(int* current, int goal)
{
	if (*current < goal)
	{
		++*current;
		return 1;
	}
	else if (*current > goal)
	{
		--*current;
		return -1;
	}
	return 0;
}

Directions::Direction MainFactory::moveXOneToGoal(int* current, int goal)
{
	int result = moveOneToGoal(current, goal);
	if (result == 1)
	{
		return Directions::East;
	}
	else if (result == -1)
	{
		return Directions::West;
	}
	return (Directions::Direction)0;
}

Directions::Direction MainFactory::moveYOneToGoal(int* current, int goal)
{
	int result = moveOneToGoal(current, goal);
	if (result == 1)
	{
		return Directions::South;
	}
	else if (result == -1)
	{
		return Directions::North;
	}
	return (Directions::Direction)0;
}

vector<vector<Room*>> MainFactory::createDungeonFloor(int* entranceXpos, int* entranceYpos, int width, int height, int level)
{
	vector<vector<Room*>> floor;
	floor.resize(width);


	int exitXpos;
	int exitYpos;

	do
	{
		exitXpos = widthDist(dre);
	} while (exitXpos == *entranceXpos);

	do
	{
		exitYpos = heightDist(dre);
	} while (exitYpos == *entranceYpos);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			floor[y].push_back(new Room(level));
			if (level == 0 && y == 0 && x == 0)
			{
				floor[y][x]->connected = true;
			}
		}
	}

	createpath(&floor, *entranceXpos, *entranceYpos, exitXpos, exitYpos, false);


	for (int y = 0; y < floor.size(); y++)
	{
		for (int x = 0; x < floor[y].size(); x++)
		{
			if (!floor[y][x]->connected)
			{
				int toX = 0;
				do
				{
					toX = widthDist(dre);
				} while (x == toX);

				int toY = 0;
				do
				{
					toY = heightDist(dre);
				} while (y == toY);

				createpath(&floor, x, y, toX, toY, true);
			}
		}
	}

	*entranceXpos = exitXpos;
	*entranceYpos = exitYpos;

	return floor;

}


void MainFactory::createpath(vector<vector<Room*>>* floor, int fromX, int fromY, int toX, int toY, bool shouldBreak)
{
	Directions::Direction direction = (Directions::Direction)0;
	uniform_int_distribution<int>binair(0, 1);

	int tempX = fromX, tempY = fromY;
	do
	{
		if (toX == tempX)
		{
			direction = moveYOneToGoal(&tempY, toY);
		}
		else if (toY == tempY)
		{
			direction = moveXOneToGoal(&tempX, toX);
		}
		else
		{
			if (binair(dre))
			{
				direction = moveYOneToGoal(&tempY, toY);
			}
			else
			{
				direction = moveXOneToGoal(&tempX, toX);
			}
		}
		if (fromX != tempX || fromY != tempY)
		{
			if (!(*floor)[fromY][fromX]->getHallway(direction))
			{
				new Hallway((*floor)[fromY][fromX], (*floor)[tempY][tempX], direction);
				if (shouldBreak && (*floor)[tempY][tempX]->connected)
				{
					break;
				}
			}
			fromX = tempX;
			fromY = tempY;

		}
	} while (fromX != toX || fromY != toY);
}



Dungeon* MainFactory::createDungeon(int width, int height, int depth)
{
	if (width < 2 || height < 2 || depth < 2)
	{
		throw new exception("Invallid Dungeon Size");
	}

	widthDist = uniform_int_distribution<int>(0, width - 1);
	heightDist = uniform_int_distribution<int>(0, height - 1);
	depthDist = uniform_int_distribution<int>(0, depth - 1);

	StartRoom* startRoom = nullptr;
	vector<vector<vector<Room*>>>rooms;
	int startXPos = widthDist(dre);
	int startYPos = heightDist(dre);

	int xpos = startXPos;
	int ypos = startYPos;
	//depth = 1;
	for (int z = 0; z < depth; z++)
	{

		rooms.push_back(createDungeonFloor(&xpos, &ypos, width, height, z));
		if (z > 0)
		{
			new Staircase(rooms[z - 1][startYPos][startXPos], rooms[z][startYPos][startXPos]);
		}
		else
		{
			startRoom = new StartRoom(rooms[z][startYPos][startXPos]->getLevel());
			rooms[z][startYPos][startXPos]->MoveHallwaysTo(startRoom);
			delete rooms[z][startYPos][startXPos];
			rooms[z][startYPos][startXPos] = startRoom;
			startRoom->setConnected();
		}
		startYPos = ypos;
		startXPos = xpos;
	}

	return new Dungeon(rooms, startRoom);
}

void MainFactory::clean()
{
	delete this;
}
