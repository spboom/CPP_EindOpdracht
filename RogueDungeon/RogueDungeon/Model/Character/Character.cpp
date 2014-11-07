#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <iostream>

//
#include "Character.h"

Character::Character() {}

Character::~Character()
{
	for (int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
}

void Character::parseXMLElement(XMLElement *xmlelement)
{
	name = xmlelement->Attribute("name");

	attackPoints = atoi(xmlelement->Attribute("attack"));

	level = atoi(xmlelement->Attribute("level"));

	maxLifepoints = lifepoints = atoi(xmlelement->Attribute("hitpoints"));

	//cout << name + " " + std::to_string(level) + " " + std::to_string(attackPoints) + "\n";
}


int Character::attack(Character* enemy)
{
	if (!isDead())
	{
		return enemy->hit(attackPoints);
	}
	return 0;
}

bool Character::isDead()
{
	return lifepoints <= 0;
}

string Character::getDiscription()
{
	if (isDead())
	{
		return "dood";
	}
	else if (lifepoints == maxLifepoints)
	{
		return "ongeschonden";
	}
	else  if (lifepoints > maxLifepoints / 2)
	{
		return "gewond";
	}
	else if (lifepoints < maxLifepoints / 4)
	{
		return "ernstig gewond";
	}
	else if (lifepoints < maxLifepoints < 8)
	{
		return "bijna dood";
	}
}

int Character::hit(int hitPoints)
{
	int damage = hitPoints - getDefence();
	if (damage > 0)
	{
		lifepoints -= damage;
		if (lifepoints < 0)
		{
			lifepoints = 0;
		}
	}
	else
	{
		damage = 0;
	}
	return damage;
}

int Character::getDefence()
{
	return attackPoints *0.5f;
}