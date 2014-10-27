#pragma once

#include "../Item/Item.h"
#include <vector>

using namespace std;

class Character
{
public:
	Character();
	~Character();

	// 
	char naam;
	int level;
	int lifepoints;
	int experience_points;
	int attack;
	int defence;
	int attraction;
	vector<Item*> items;


private:
};

