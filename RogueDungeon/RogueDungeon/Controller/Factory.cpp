//
#include <tchar.h>
#include <strsafe.h>

//
#include "Factory.h"
#include "../Model/Location/Directions.h"
#include "../Model/Location/Staircase.h"
#include <vector>

using namespace std;

Factory::Factory()
{
	dre = default_random_engine(dev());
}


Factory::~Factory()
{
}

int Factory::moveOneToGoal(int* current, int goal)
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

Directions Factory::moveXOneToGoal(int* current, int goal)
{
	int result = moveOneToGoal(current, goal);
	if (result == 1)
	{
		return East;
	}
	else if (result == -1)
	{
		return West;
	}
}

Directions Factory::moveYOneToGoal(int* current, int goal)
{
	int result = moveOneToGoal(current, goal);
	if (result == 1)
	{
		return North;
	}
	else if (result == -1)
	{
		return South;
	}
	return (Directions)0;
}

vector<vector<Room*>> Factory::createDungeonFloor(int* entranceXpos, int* entranceYpos, int width, int height)
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

	int x = *entranceXpos;
	int y = *entranceYpos;
	Room* currentRoom = floor[y][x];
	Directions direction;
	do
	{
		int tempX = x, tempY = y;
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
		if (x != tempX || y != tempY)
		{
			new Hallway(floor[y][x], floor[tempY][tempX], direction);

			x = tempX;
			y = tempY;

		}
	} while (x != exitXpos&&y != exitYpos);

	//TODO fill floor Random!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	*entranceXpos = exitXpos;
	*entranceYpos = exitYpos;

	return floor;

}

vector<vector<vector<Room*>>> Factory::createDungeon(int width, int height, int depth)
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
	for (int z = 0; z < depth; z++)
	{

		rooms.push_back(createDungeonFloor(&xpos, &ypos, width, height));
		if (z > 0)
		{
			new Staircase(rooms[z - 1][ypos][xpos], rooms[z][ypos][xpos]);
		}

	}

	return rooms;
}

//Room linkRoom(Room* connected, Room* room, Directions direction)
//{
//	Hallway* hall = new Hallway();
//}