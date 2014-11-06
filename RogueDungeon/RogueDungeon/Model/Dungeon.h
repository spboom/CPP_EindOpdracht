#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include "Location\Room.h"
#include "Location\StartRoom.h"

class Dungeon
{
public:
	Dungeon(vector<vector<vector<Room*>>> dungeon, StartRoom* start);
	~Dungeon();
	vector<vector<Room*>> getFloor(int level);
	StartRoom* getStart();
private:
	StartRoom* startRoom;
	vector<vector<vector<Room*>>> dungeon;

};
#endif /* _DUNGEON_H_ */