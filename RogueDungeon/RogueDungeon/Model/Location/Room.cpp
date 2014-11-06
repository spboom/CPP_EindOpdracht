#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include "Room.h"
#include "Directions.h"
#include <map>

//
using namespace std;


Room::Room()
{
	connected = false;
}

//Room::Room(map<Directions, Hallway> doors, Item *items) : connected(false)
//{
//	Doors = doors;
//	Items = items;
//}

void Room::setItems(Item *items)
{
	Items = items;
}

Room::~Room()
{

	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) {
		if (iterator->second != NULL)
		{
			delete iterator->second;
			iterator->second = NULL;
		}
	}
}

void Room::delHallway(Hallway* hall)
{
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) {
		if (iterator->second == hall)
		{
			iterator->second = NULL;
			break;
		}
	}
}

void Room::addHallway(Hallway* hallway, Directions direction)
{
	Doors[direction] = hallway;
}

char Room::getSymbol()
{
	return 'N';
}

bool Room::hasHallway(Directions direction)
{
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) {
		if (iterator->first == direction)
		{
			return true;
		}
	}
	return false;
}