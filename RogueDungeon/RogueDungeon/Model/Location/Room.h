#ifndef _ROOM_H_
#define _ROOM_H_

//
#include "Location.h"
#include "Hallway.h"
#include "../Item/Item.h"
#include "../../Model/Location/Trap.h"
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
	map<Directions::Direction, Hallway*> getDoors();
	Room* getRoomInDirection(Directions::Direction direction);
	//
	string characteristic;
	string feature;
	string state;
	string object;
	string exit;
	string enemy;
	string getDescription();
	string getExits();
	string getEnemy();
	string getGeneralDescription();
	string getGamePlayMenu();
	vector<Enemy*> enemies;
	vector<Item*> items;
	Trap* trap;
private:
	int level;
	map<Directions::Direction, Hallway*> Doors;
};
#endif /* defined(_ROOM_H_) */
