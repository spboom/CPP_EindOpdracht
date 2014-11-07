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
#include "ItemFactory.h"
#include "../Model/Item/Item.h"
#include "../Model/Item/ConsumableItem.h"
#include "../Model/Item/UsableItem.h"
#include "../Model/Item/WearableItem.h"
#include "../Enum/Enum.h"

//
ItemFactory* ItemFactory::s_pInstance;

//
using namespace std;
using namespace tinyxml2;

ItemFactory::ItemFactory() :MainFactory()
{

}

ItemFactory::~ItemFactory()
{
	for (int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
}

vector<Item*> ItemFactory::parseXML(string xmlPath) {
	// Read from file
	XMLDocument doc;
	doc.LoadFile(xmlPath.c_str());
	// Text is just another Node to TinyXML-2. The more
	// general way to get to the XMLText:
	XMLElement *node = doc.FirstChildElement("items")->FirstChildElement("item")->ToElement();
	vector<Item*> items;
	for (node; node; node = node->NextSiblingElement())
	{
		Item *item = NULL;
		Enum *e = NULL;
		string item_type;

		item_type = node->Attribute("type");

		switch (e->getItemEnum(item_type))
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
		item->parseXMLElement(node);
		items.push_back(item);
	}
	return items;
}

void TheItemFactory::fillRoom(Room* room)
{

}