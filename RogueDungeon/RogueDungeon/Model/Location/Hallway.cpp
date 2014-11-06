#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//

//
#include "Hallway.h"
#include  "Room.h"

//

Hallway::Hallway(Room* from, Room* to, Directions::Direction direction)
{
	if (from == to)
	{
		throw exception("Can't create Hallway to and from the same room");
	}
	room1 = from;
	room2 = to;
	from->addHallway(this, direction);
	int dif = -1;
	if (direction % 2 == 1)
	{
		dif *= -1;
	}
	int dir = direction;
	direction = static_cast<Directions::Direction>(dir + dif);

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

void Hallway::changeRoom(Room* from, Room* to)
{
	Directions::Direction direction = from->getDirection(this);
	if (room1 == from)
	{
		room1 = to;
		to->addHallway(this, direction);
	}
	else if (room2 == from)
	{
		room2 = to;
		to->addHallway(this, direction);
	}
}