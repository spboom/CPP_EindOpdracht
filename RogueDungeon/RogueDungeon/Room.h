#ifndef _ROOM_H_
#define _ROOM_H_

//
#include "Location.h"
#include "Hallway.h"
#include "Item.h"
#include "Directions.h"
#include <map>

//
using namespace std;

class Room : public Location
{
public:
	Room();
	Room(map<Directions, Hallway> doors, Item *items) : connected() {}
	~Room();
	bool connected;
	bool visited;
	void link(Room* room, Directions direction);
	void setItems(Item *items);
private:
	
};
#endif /* defined(_ROOM_H_) */
