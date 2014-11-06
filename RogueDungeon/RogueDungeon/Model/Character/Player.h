#pragma once
#include "Character.h"
#include "tinyxml2.h"

//
using namespace tinyxml2;

class Player : public Character
{
public:
	Player();
	~Player();
	
	void parseXMLElement(XMLElement *xmlelement);
};

