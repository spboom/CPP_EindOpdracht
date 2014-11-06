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
#include "../Model/Dungeon.h"
#include "../Model/Location/StartRoom.h"

//
using namespace std;
using namespace tinyxml2;

MainFactory* MainFactory::s_pInstance;

MainFactory::MainFactory()
{
	dre = default_random_engine(dev());
	characteristics = new vector<string>();
}

MainFactory::~MainFactory()
{
	delete characteristics;
}

void MainFactory::fillAllVectors()
{
	// TheController::Instance()->xmlFileController("Inputfiles/Room/room_characteristics.xml", MainFactory::characteristics);
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

vector<vector<Room*>> MainFactory::createDungeonFloor(int* entranceXpos, int* entranceYpos, int width, int height)
{
	vector<vector<Room*>> floor;
	floor.resize(width);

	uniform_int_distribution<int>binair(0, 1);

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
			floor[y].push_back(new Room());
		}
	}

	int xPos = *entranceXpos;
	int yPos = *entranceYpos;
	Directions::Direction direction;

	int tempX = xPos, tempY = yPos;
	do
	{
		if (exitXpos == tempX)
		{
			direction = moveYOneToGoal(&tempY, exitYpos);
		}
		else if (exitYpos == tempY)
		{
			direction = moveXOneToGoal(&tempX, exitXpos);
		}
		else
		{
			if (binair(dre))
			{
				direction = moveYOneToGoal(&tempY, exitYpos);
			}
			else
			{
				direction = moveXOneToGoal(&tempX, exitXpos);
			}
		}
		if (xPos != tempX || yPos != tempY)
		{
			new Hallway(floor[yPos][xPos], floor[tempY][tempX], direction);

			xPos = tempX;
			yPos = tempY;

		}
	} while (xPos != exitXpos || yPos != exitYpos);

	//TODO fill floor Random!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	*entranceXpos = exitXpos;
	*entranceYpos = exitYpos;

	return floor;

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

	vector<vector<vector<Room*>>>rooms;
	int startXPos = widthDist(dre);
	int startYPos = heightDist(dre);

	int xpos = startXPos;
	int ypos = startYPos;
	//depth = 1;
	for (int z = 0; z < depth; z++)
	{

		rooms.push_back(createDungeonFloor(&xpos, &ypos, width, height));
		if (z > 0)
		{
			new Staircase(rooms[z - 1][startYPos][startXPos], rooms[z][startYPos][startXPos]);
		}
		else
		{
			Room* start = new StartRoom();
			rooms[z][startYPos][startXPos]->MoveHallwaysTo(start);
			delete rooms[z][startYPos][startXPos];
			rooms[z][startYPos][startXPos] = start;
		}
		startYPos = ypos;
		startXPos = xpos;

	}

	return new Dungeon(rooms);
}

void MainFactory::clean()
{
	delete this;
}
