#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <string>

//
#include "Enum.h"

//
using namespace std;

Enum::Enum(){}
Enum::~Enum(){}

int Enum::getItemEnum(string itemname)
{
	if (itemname == "item")
	{
		return ITEM;
	}
	else if (itemname == "consumableitem")
	{
		return CONSUMABLE_ITEM;
	}
	else if (itemname == "usableitem")
	{
		return USABLE_ITEM;
	}
	else if (itemname == "wearableitem")
	{
		return WEARABLE_ITEM;
	}
}

int Enum::getLocationEnum(string locationname)
{
	if (locationname == "room")
	{
		return ROOM;
	}
	else if (locationname == "hallway")
	{
		return HALLWAY;
	}
	else if (locationname == "staircase")
	{
		return STAIRCASE;
	}
	else if (locationname == "trap")
	{
		return TRAP;
	}
}