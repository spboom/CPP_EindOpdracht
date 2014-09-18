#include "stdafx.h"
#include "Factory.h"


Factory::Factory()
{
}


Factory::~Factory()
{
}

Room createDungeon(int width, int height)
{
	Room **rooms = new Room*[width];

	for (int x = 0; x < width; x++)
	{
		rooms[x] = new Room[height];
		for (int y = 0; y < height; y++)
		{

		}
	}
}