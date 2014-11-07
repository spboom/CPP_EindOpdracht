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
#include <iostream>
#include "../../Factory/MainFactory.h"

//
using namespace std;

Room::Room(int level)
{
	TheFactory::Instance()->fillRoom(this);
	connected = false;
	visited = true;
	this->level = level;
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

map<Directions::Direction, Hallway*> Room::getDoors()
{
	return Doors;
}

string Room::getDescription()
{
	stringstream description;
	description << "Beschrijving: Je staat in een " << characteristic << " " << state << " kamer met in het midden een " << object << ". De kamer wordt verlicht door een " << feature + "\n";
	return description.str();
}

string Room::getExits()
{
	stringstream exits;
	exits << "Uitgangen: " << + "\n";
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++) 
	{
		exits << iterator->second->getDescription();
	}
	return exits.str();
}

string Room::getEnemy()
{
	stringstream enemy;
	enemy << "Aanwezig: " << +"\n";
	return enemy.str();
}

string Room::getGeneralDescription()
{
	stringstream enemy;
	enemy << "Wat doe je?" << +"\n";
	return enemy.str();
}

string Room::getGamePlayMenu()
{
	stringstream enemy;
	enemy << "[vecht|vlucht|zoek|rust uit|bekijk spullen|bekijk kaart]" << "\n\n" << "Actie: ";
	return enemy.str();
}

int Room::getLevel()
{
	return level;
}

Room* Room::getRoomInDirection(Directions::Direction direction)
{
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++)
	{
		if (iterator->first == direction)
		{
			return iterator->second->getOtherRoom(this);
		}
	}
}

void Room::setConnected()
{
	connected = true;
	for (auto iterator = Doors.begin(); iterator != Doors.end(); iterator++)
	{
		Room* other = iterator->second->getOtherRoom(this);
		if (!other->connected)
		{
			other->setConnected();
		}
	}
}
