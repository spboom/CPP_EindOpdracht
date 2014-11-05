#pragma once
#include "Hallway.h"
class Staircase :
	public Hallway
{
public:
	Staircase(Room* from, Room* to);
	virtual  ~Staircase();
};

