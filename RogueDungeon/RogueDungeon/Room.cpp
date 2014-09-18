#include "stdafx.h"
#include "Room.h"


Hallway *Directions;
Item *Items;

Room::Room()
{

}

Room::Room(Hallway *directions, Item *items)
{
	Directions = directions;
	Items = items;
}

Room::~Room()
{
}
