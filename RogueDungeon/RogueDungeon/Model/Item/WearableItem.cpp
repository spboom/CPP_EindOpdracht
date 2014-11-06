#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>

//
#include "WearableItem.h"

//
#include <iostream>

WearableItem::WearableItem() {}
WearableItem::~WearableItem() {}

void WearableItem::message()
{
	cout << "Enemy derives from Character!";
}

void WearableItem::parseXMLElement(XMLElement *xmlelement)
{
	Item::parseXMLElement(xmlelement);
}