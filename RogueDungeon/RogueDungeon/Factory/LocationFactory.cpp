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
#include "../Model/Character/Enemy/Enemy.h"
#include "../Enum/Enum.h"

//
LocationFactory* LocationFactory::s_pInstance;

//
using namespace std;
using namespace tinyxml2;

LocationFactory::LocationFactory()
{

}

LocationFactory::~LocationFactory()
{

}

void LocationFactory::parseXML(string xmlPath) {
	// Read from file
	XMLDocument doc;
	doc.LoadFile(xmlPath.c_str());
	// Text is just another Node to TinyXML-2. The more
	// general way to get to the XMLText:
	XMLElement *node = doc.FirstChildElement("enemies")->FirstChildElement("enemy")->ToElement();
	for (node; node; node = node->NextSiblingElement())
	{
		// Item *item = NULL; --> veranderen naar BASE CLASS location
		Enum *e = NULL;
		string location_type;

		location_type = node->Attribute("location");

		/*switch (e->getLocationEnum(location_type))
		{
		case Enum::ITEM:
			item = new Item();
			break;
		case Enum::CONSUMABLE_ITEM:
			item = new ConsumableItem();
			break;
		case Enum::USABLE_ITEM:
			item = new UsableItem();
			break;
		case Enum::WEARABLE_ITEM:
			item = new WearableItem();
			break;
		default:
			item = NULL;
			break;
		}
		item->parseXMLElement(node);*/
	}
}
