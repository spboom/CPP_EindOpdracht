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

Hallway::~Hallway()
{
	room1->delHallway(this);
	room2->delHallway(this);
}