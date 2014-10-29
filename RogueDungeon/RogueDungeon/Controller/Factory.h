#pragma once

//
#include "../Model/Location/Room.h";

class Factory
{
public:
	Factory();
	~Factory();

	Room* Factory::createDungeon(int width, int height, int depth);

private:
	Room** createDungeonFloor(int entranceXpos, int entranceYpos, int width, int height);


	random_device dev;
	default_random_engine dre;
	uniform_int_distribution<int> widthDist;
	uniform_int_distribution<int> heightDist;
	uniform_int_distribution<int> depthDist;
	;
};

