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
#include "CharacterFactory.h"
#include "../Model/Character/Enemy/Enemy.h"

//
CharacterFactory* CharacterFactory::s_pInstance;

//
using namespace std;
using namespace tinyxml2;

CharacterFactory::CharacterFactory() :MainFactory()
{

}

CharacterFactory::~CharacterFactory()
{
	for (int i = 0; i < characters.size(); i++)
	{
		delete characters[i];
	}
}

vector<Enemy*> CharacterFactory::parseXML(string xmlPath) {
	// Read from file
	XMLDocument doc;
	doc.LoadFile(xmlPath.c_str());
	// Text is just another Node to TinyXML-2. The more
	// general way to get to the XMLText:
	XMLElement *node = doc.FirstChildElement("enemies")->FirstChildElement("enemy")->ToElement();
	for (node; node; node = node->NextSiblingElement())
	{
		Enemy* character = new Enemy();
		character->parseXMLElement(node);
		characters.push_back(character);
	}
	return characters;
}

void CharacterFactory::fillRoom(Room* room)
{
	if (chance(dre) < 101)
	{
		room->enemies.push_back(getRandomCharacter());
	}
}

Enemy* CharacterFactory::getRandomCharacter()
{
	uniform_int_distribution<int> lengthDist(0, characters.size() - 1);
	return characters[lengthDist(dre)];
}
