#pragma once
#include "Room.h";

class Factory
{
public:
	Factory();
	~Factory();

	Room createDungeon(int width, int height);
};

