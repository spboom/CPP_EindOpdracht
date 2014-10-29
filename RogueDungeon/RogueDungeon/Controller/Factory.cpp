//
#include <tchar.h>
#include <strsafe.h>

//
#include "Factory.h"
#include "../Model/Location/Directions.h"
#include <vector>
#include <random>

using namespace std;

Factory::Factory()
{
	dre = default_random_engine(dev());
}


Factory::~Factory()
{
}

Room** Factory::createDungeonFloor(int entranceXpos, int entranceYpos, int width, int height)
{
	Room** floor = new Room*[height];
	for (int y = 0; y < height; y++)
	{
		floor[y] = new Room[width];
	}
}

Room* Factory::createDungeon(int width, int height, int depth)
{
	widthDist = uniform_int_distribution<int>(0, width);
	heightDist = uniform_int_distribution<int>(0, height);
	depthDist = uniform_int_distribution<int>(0, depth);

	Room ***rooms = new Room**[depth];

	for (int z = 0; z < depth; z++)
	{
		rooms[z] = createDungeonFloor(widthDist(dre), heightDist(dre), width, height);
	}

	/*int connected = 0;
	vector<Room> notConnectedRooms = vector<Room>();

	while (connected < width*height)
	{
	rooms[0][0].connected = true;
	connected++;
	}*/

	return nullptr;
}

//Room linkRoom(Room* connected, Room* room, Directions direction)
//{
//	Hallway* hall = new Hallway();
//}