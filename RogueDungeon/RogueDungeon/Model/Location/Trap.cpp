#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include "tinyxml2.h"

//
#include "Trap.h"

//
using namespace std;
using namespace tinyxml2;

Trap::Trap()
{
	damage = 0;
}


Trap::~Trap()
{
}

void Trap::parseXML(XMLElement *xmlelement)
{
	if (xmlelement->Attribute("name"))
	{
		name = xmlelement->Attribute("name");
	}
	if (xmlelement->Attribute("damage"))
	{
		damage = atoi(xmlelement->Attribute("damage"));
	}
}