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

CharacterFactory::CharacterFactory()
{

}

CharacterFactory::~CharacterFactory()
{

}

void CharacterFactory::parseXML(string xmlPath) {
	// Read from file
	XMLDocument doc;
	doc.LoadFile(xmlPath.c_str());
	// Text is just another Node to TinyXML-2. The more
	// general way to get to the XMLText:
	XMLElement *node = doc.FirstChildElement("enemies")->FirstChildElement("enemy")->ToElement();
	for (node; node; node = node->NextSiblingElement())
	{
		Character *character = NULL;
		character = new Enemy();
		character->parseXMLElement(node);
	}
}
