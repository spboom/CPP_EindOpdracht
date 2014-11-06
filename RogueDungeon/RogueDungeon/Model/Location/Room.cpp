#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include "Room.h"
#include "Directions.h"
#include <map>
#include <string>
#include <sstream>
#include "../../Factory/MainFactory.h"

//
using namespace std;

Room::Room()
{
	TheFactory::Instance()->fillRoom(this);
	connected = false;
	visited = true;
}

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

void Room::addHallway(Hallway* hallway, Directions::Direction direction)
{
	Doors[direction] = hallway;
}

char Room::getSymbol()
{
	if (!visited)
	{
		return '.';
	}
	else
	{
		if (hasHallway(Directions::Down))
		{
			return 'L';
		}
		else if (hasHallway(Directions::Up))
		{
			return 'H';
		}
		return 'N';
	}
}

bool Room::hasHallway(Directions::Direction direction)
{
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) {
		if (iterator->first == direction)
		{
			return true;
		}
	}
	return false;
}

Hallway* Room::getHallway(Directions::Direction direction)
{
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) {
		if (iterator->first == direction)
		{
			return iterator->second;
		}
	}
	return NULL;
}

void Room::MoveHallwaysTo(Room* room)
{
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) {
		iterator->second->changeRoom(this, room);
		iterator->second = NULL;
	}
}

Directions::Direction Room::getDirection(Hallway* hallway)
{
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) {
		if (iterator->second == hallway)
		{
			return iterator->first;
		}
	}
	return (Directions::Direction)0;
}

string Room::getDescription()
{
	stringstream description;

	description << "Beschrijving: Je staat in een " << characteristic << " " << state << " kamer met in het midden een " << object << ". Het wordt verlicht door een " << feature;

	return description.str();
}
