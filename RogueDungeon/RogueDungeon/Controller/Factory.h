#pragma once

//
#include "../Model/Location/Room.h";

class Factory
{
public:
	Factory();
	~Factory();

	Room* createDungeon(int width, int height);
};

