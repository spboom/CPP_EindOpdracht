#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <iostream>

//
#include "Enemy.h"

//
using namespace std;

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::message()
{
	cout << "Enemy derives from Character!";
}

void Enemy::parseXMLElement(XMLElement *xmlelement)
{
	if (xmlelement->Attribute("boss"))
	{
		boss = xmlelement->Attribute("boss");
		endboss = true;
	}

	cout << boss;

	Character::parseXMLElement(xmlelement);
}
