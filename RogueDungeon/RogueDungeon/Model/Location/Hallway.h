#ifndef _HALLWAY_H_
#define _HALLWAY_H_

//
#include "Location.h"
#include "Directions.h"
#include "Trap.h"

//

//
using namespace std;

class Room;
class Hallway : public Location
{
public:
	bool Hallway::connectedToVisited();
	Hallway(Room* from, Room* to, Directions::Direction direction);
	virtual ~Hallway();
	void changeRoom(Room* from, Room* to);
	Room* getOtherRoom(Room* from);
	void connect();
	string getDescription();
	string discription;
	//
	Trap* trap;

private:
	Room* room1;
	Room* room2;
};
#endif /* _HALLWAY_H_ */
