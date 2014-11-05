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
	Room(map<Directions, Hallway> doors, Item *items);
	virtual ~Room();
	bool connected;
	bool visited;
	void addHallway(Hallway* hallway, Directions direction);
	void setItems(Item *items);
	void delHallway(Hallway* hall);
private:
	map<Directions, Hallway*> Doors;
	Item* Items;
};
#endif /* defined(_ROOM_H_) */
