#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <iostream>

//
#include "Character.h"

Character::Character() {}

Character::~Character()
{
	for (int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
}

void Character::parseXMLElement(XMLElement *xmlelement)
{
	name = xmlelement->Attribute("name");

	attack = atoi(xmlelement->Attribute("attack"));

	level = atoi(xmlelement->Attribute("level"));

	//cout << name + " " + std::to_string(level) + " " + std::to_string(attack) + "\n";
}
