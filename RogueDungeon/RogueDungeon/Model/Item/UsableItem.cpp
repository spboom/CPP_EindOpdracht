#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>

//
#include "UsableItem.h"

//
#include <iostream>

UsableItem::UsableItem() {}
UsableItem::~UsableItem() {}

void UsableItem::message()
{
	cout << "Enemy derives from Character!";
}

void UsableItem::parseXMLElement(XMLElement *xmlelement)
{
	Item::parseXMLElement(xmlelement);
}