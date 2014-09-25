#pragma once
#include "Location.h"
#include "Hallway.h"
#include "Item.h"
#include "Directions.h"


class Room :
	public Location
{

public:
	bool connected;
	Room::Room();
	Room::Room(map<Directions, Hallway> doors, Item *items);

	void link(Room* room, Directions direction);
	void setItems(Item *items);

	~Room();
};

