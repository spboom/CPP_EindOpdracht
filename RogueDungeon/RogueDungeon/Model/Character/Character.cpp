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

void Character::parseXMLElement(XMLElement *xmlelement)
{

	name = xmlelement->Attribute("name");

	attack = atoi(xmlelement->Attribute("attack"));

	level = atoi(xmlelement->Attribute("level"));

	if (xmlelement->Attribute("boss"))
	{
		boss = xmlelement->Attribute("boss");
		endboss = true;
	}

	cout << name + " " + std::to_string(level) + " " + std::to_string(attack) + " " +  boss + "\n";
}
