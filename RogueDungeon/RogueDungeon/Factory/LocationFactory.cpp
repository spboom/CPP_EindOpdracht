#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <string>
#include "tinyxml2.h"
#include <iostream>

//
#include "LocationFactory.h"
#include "../Model/Location/Location.h"
#include "../Model/Location/Hallway.h"
#include "../Enum/Enum.h"

//
LocationFactory* LocationFactory::s_pInstance;

//
using namespace std;
using namespace tinyxml2;

LocationFactory::LocationFactory() : MainFactory()
{
	room_characteristics = vector<string>();
	room_feature = vector<string>();
	room_state = vector<string>();
	room_trap = vector<string>();
	room_exits = vector<string>();
	room_items = vector<string>();
}

LocationFactory::~LocationFactory()
{
	for (int i = 0; i < locations.size(); i++)
	{
		delete locations[i];
	}
}

vector<Location*> LocationFactory::parseXML(string xmlPath) {
	// Read from file
	XMLDocument doc;
	doc.LoadFile(xmlPath.c_str());
	// Text is just another Node to TinyXML-2. The more
	// general way to get to the XMLText:
	XMLElement *node = doc.FirstChildElement("locations")->FirstChildElement("location")->ToElement();
	for (node; node; node = node->NextSiblingElement())
	{
		Location *location = new Location();

		type = node->Attribute("type");
		name = node->Attribute("name");

		if ("characteristic" == type)
		{
			room_characteristics.push_back(name);
		}
		else if ("feature" == type)
		{
			room_feature.push_back(name);
		}
		else if ("state" == type)
		{
			room_state.push_back(name);
		}
		else if ("trap" == type)
		{
			room_trap.push_back(name);
		}
		else if ("exit" == type)
		{
			room_exits.push_back(name);
		}
		else if ("item" == type)
		{
			room_items.push_back(name);
		}

		location->parseXMLElement(node);
		locations.push_back(location);
	}
	return locations;
}

void LocationFactory::fillRoom(Room* room)
{
	uniform_int_distribution<int> arrayDist(0, room_characteristics.size() - 1);
	room->characteristic = room_characteristics[arrayDist(dre)];

	arrayDist = uniform_int_distribution<int>(0, room_feature.size() - 1);
	room->feature = room_feature[arrayDist(dre)];

	arrayDist = uniform_int_distribution<int>(0, room_state.size() - 1);
	room->state = room_state[arrayDist(dre)];

	arrayDist = uniform_int_distribution<int>(0, room_items.size() - 1);
	room->object = room_items[arrayDist(dre)];

	arrayDist = uniform_int_distribution<int>(0, room_exits.size() - 1);
	room->exit = room_exits[arrayDist(dre)];

	if (chance(dre) < 25)
	{
		room->trap = new Trap(*getRandomTrap());
	}
}

void LocationFactory::fillHallway(Hallway* hallway)
{
	if (chance(dre) < 25)
	{
		hallway->trap = new Trap(*getRandomTrap());
	}

	uniform_int_distribution<int> arrayDist(0, room_exits.size() - 1);
	hallway->discription = room_exits[arrayDist(dre)];
}

Trap* LocationFactory::getRandomTrap()
{
	uniform_int_distribution<int> lengthDist(0, traps.size() - 1);
	return traps[lengthDist(dre)];
}
