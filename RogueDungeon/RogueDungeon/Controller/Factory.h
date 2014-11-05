#pragma once

//
#include "../Model/Location/Room.h";
#include <random>

class Factory
{
public:
	Factory();
	~Factory();

	vector<vector<vector<Room*>>> createDungeon(int width, int height, int depth);

private:
	vector<vector<Room*>> createDungeonFloor(int* entranceXpos, int* entranceYpos, int width, int height);
	int moveOneToGoal(int* current, int goal);
	Directions moveXOneToGoal(int* current, int goal);
	Directions moveYOneToGoal(int* current, int goal);

	random_device dev;
	default_random_engine dre;
	uniform_int_distribution<int> widthDist;
	uniform_int_distribution<int> heightDist;
	uniform_int_distribution<int> depthDist;
};

