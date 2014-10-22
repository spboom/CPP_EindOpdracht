#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include "stdafx.h"
#include "Room.h"
#include "Directions.h"
#include <map>

//
using namespace std;

map<Directions, Hallway> Doors;
Item *Items;

Room::Room() : connected(false)
{

}

//Room::Room(map<Directions, Hallway> doors, Item *items) : connected(false)
//{
//	Doors = doors;
//	Items = items;
//}

void Room::link(Room* room, Directions direction)
{
	Hallway *hall = new Hallway();
	//TODO set room to hallway
	Doors.insert(make_pair(direction, *hall));
}

void Room::setItems(Item *items)
{
	Items = items;
}

Room::~Room()
{
}
