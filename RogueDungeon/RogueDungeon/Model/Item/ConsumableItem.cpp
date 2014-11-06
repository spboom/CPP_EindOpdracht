#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>

//
#include "ConsumableItem.h"

//
#include <iostream>

ConsumableItem::ConsumableItem() {}
ConsumableItem::~ConsumableItem() {}

void ConsumableItem::message()
{
	cout << "Enemy derives from Character!";
}

void ConsumableItem::parseXMLElement(XMLElement *xmlelement)
{
	Item::parseXMLElement(xmlelement);
}