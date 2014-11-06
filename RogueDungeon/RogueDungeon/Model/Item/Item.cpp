#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <iostream>
#include "tinyxml2.h"

//
#include "Item.h"

//
using namespace std;
using namespace tinyxml2;

void Item::parseXMLElement(XMLElement *xmlelement)
{
	name = xmlelement->Attribute("name");

	type = xmlelement->Attribute("type");

	cout << name + " " + type + "\n";
}
