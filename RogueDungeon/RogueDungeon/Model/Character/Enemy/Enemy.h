#ifndef _ENEMY_H_
#define _ENEMY_H_

//
#include "../Character.h"
#include "tinyxml2.h"
#include <string>

//
using namespace std;
using namespace tinyxml2;

/*Derived class Enemy from Character*/
/*Base Class*/
class Enemy : public Character
{
public:
	virtual void message();
	void parseXMLElement(XMLElement *xmlelement);
private:
};
#endif /* _ENEMY_H_ */
