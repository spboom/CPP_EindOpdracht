#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//

//
#include "Dungeon.h"

//

Dungeon::Dungeon(vector<vector<vector<Room*>>> dungeon, StartRoom* start)
{
	this->dungeon = dungeon;
	startRoom = start;
}

Dungeon::~Dungeon()
{
	for (int z = 0; z < dungeon.size(); z++)
	{
		for (int y = 0; y < dungeon[z].size(); y++)
		{
			for (int x = 0; x < dungeon[z][y].size(); x++)
			{
				delete dungeon[z][y][x];
			}
		}
	}
}

vector<vector<Room*>> Dungeon::getFloor(int level)
{
	return dungeon[level];
}

StartRoom* Dungeon::getStart()
{
	return startRoom;
}