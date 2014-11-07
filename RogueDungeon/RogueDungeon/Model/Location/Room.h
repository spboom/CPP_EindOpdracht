#ifndef _ROOM_H_
#define _ROOM_H_

//
#include "Location.h"
#include "Hallway.h"
#include "../Item/Item.h"
#include "Directions.h"
#include "../Character/Enemy/Enemy.h"
#include <map>

//
using namespace std;

class Room : public Location
{
public:
	Room(int level);
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
	int getLevel();
	void setConnected();
	Room* getRoomInDirection(Directions::Direction direction);
	//
	string characteristic;
	string feature;
	string state;
	string object;
	string exit;
	string getDescription();
	string getExits();
	vector<Enemy*> enemies;
private:
	int level;
	map<Directions::Direction, Hallway*> Doors;
	Item* Items;
};
#endif /* defined(_ROOM_H_) */
