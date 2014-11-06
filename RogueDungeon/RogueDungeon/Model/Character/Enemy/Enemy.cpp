#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>

//
#include "Enemy.h"

//
#include <iostream>

void Enemy::message()
{
	cout << "Enemy derives from Character!";
}

void Enemy::parseXMLElement(XMLElement *xmlelement)
{
	Character::parseXMLElement(xmlelement);
}