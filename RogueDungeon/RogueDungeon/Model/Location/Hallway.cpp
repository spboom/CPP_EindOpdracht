#include "Hallway.h"
#include  "Room.h"


Hallway::Hallway(Room* from, Room* to, Directions direction)
{
	room1 = from;
	room2 = to;
	from->addHallway(this, direction);
	int dif = -1;
	if (direction % 2 == 1)
	{
		dif *= -1;
	}
	int dir = direction;
	direction = static_cast<Directions>(dir + dif);

	to->addHallway(this, direction);
}

bool Hallway::connectedToVisited()
{
	return room1->visited || room2->visited;
}

Hallway::~Hallway()
{
	room1->delHallway(this);
	room2->delHallway(this);
}