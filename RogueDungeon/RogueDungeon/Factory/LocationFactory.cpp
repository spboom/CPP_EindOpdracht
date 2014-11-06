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
#include "../Enum/Enum.h"

//
LocationFactory* LocationFactory::s_pInstance;

//
using namespace std;
using namespace tinyxml2;

LocationFactory::LocationFactory()
{
	room_characteristics = new vector<string>();
	room_feature = new vector<string>();
	room_state = new vector<string>();
	room_trap = new vector<string>();
}

LocationFactory::~LocationFactory()
{
	delete room_feature;
	delete room_characteristics;
	delete room_state;
	delete room_trap;
}

vector<Location*> LocationFactory::parseXML(string xmlPath) {
	// Read from file
	XMLDocument doc;
	doc.LoadFile(xmlPath.c_str());
	// Text is just another Node to TinyXML-2. The more
	// general way to get to the XMLText:
	XMLElement *node = doc.FirstChildElement("locations")->FirstChildElement("location")->ToElement();
	vector<Location*> locations;
	for (node; node; node = node->NextSiblingElement())
	{
		Location *location = new Location();

		type = node->Attribute("type");
		name = node->Attribute("name");

		if ("characteristic" == type)
		{
			room_characteristics->push_back(name);
		}
		else if ("feature" == type)
		{
			room_feature->push_back(name);
		}
		else if ("state" == type)
		{
			room_state->push_back(name);
		}
		else if ("trap" == type)
		{
			room_trap->push_back(name);
		}

		location->parseXMLElement(node);
		locations.push_back(location);
	}
	return locations;
}

void LocationFactory::fillRoom(Room* room)
{

}