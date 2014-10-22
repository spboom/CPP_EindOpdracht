#include "stdafx.h"
#include "Factory.h"
#include "Directions.h"
#include <vector>

using namespace std;

Factory::Factory()
{
}


Factory::~Factory()
{
}

Room* createDungeon(int width, int height)
{
	Room **rooms = new Room*[width];

	for (int x = 0; x < width; x++)
	{
		rooms[x] = new Room[height];
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