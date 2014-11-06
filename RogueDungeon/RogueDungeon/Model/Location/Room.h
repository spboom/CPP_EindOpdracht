#ifndef _ROOM_H_
#define _ROOM_H_

//
#include "Location.h"
#include "Hallway.h"
#include "../Item/Item.h"
#include "Directions.h"
#include <map>

//
using namespace std;

class Room : public Location
{
public:
	Room();
	virtual ~Room();
	bool connected;
	bool visited;
	void addHallway(Hallway* hallway, Directions::Direction direction);
	void setItems(Item *items);
	void delHallway(Hallway* hall);
	virtual char getSymbol();
	Hallway* getHallway(Directions::Direction direction);
	bool hasHallway(Directions::Direction direction);
	void MoveHallwaysTo(Room* room);
	Directions::Direction getDirection(Hallway* hallway);

private:
	map<Directions::Direction, Hallway*> Doors;
	Item* Items;
};
#endif /* defined(_ROOM_H_) */
