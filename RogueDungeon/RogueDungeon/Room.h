#pragma once
#include "Location.h"
#include "Hallway.h"
#include "Item.h"


class Room :
	public Location
{
public:
	Room::Room();
	Room::Room(Hallway *directions, Item *items);
	~Room();
};

