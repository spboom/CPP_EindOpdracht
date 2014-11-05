#pragma once

#include "Location.h"
#include "Directions.h"

class Room;

class Hallway :
	public Location
{
public:
	Hallway(Room* from, Room* to, Directions direction);
	virtual ~Hallway();
private:
	Room* room1;
	Room* room2;
};

