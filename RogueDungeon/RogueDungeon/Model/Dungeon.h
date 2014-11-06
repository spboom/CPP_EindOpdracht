#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include "Location\Room.h"

class Dungeon
{
public:
	Dungeon(vector<vector<vector<Room*>>> dungeon);
	~Dungeon();
	vector<vector<Room*>> getFloor(int level);

private:
	vector<vector<vector<Room*>>> dungeon;

};
#endif /* _DUNGEON_H_ */