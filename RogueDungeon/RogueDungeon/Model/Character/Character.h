#ifndef _CHARACTER_H_
#define _CHARACTER_H_

// 
#include "../Item/Item.h"

//
#include <vector>
#include <string>
#include "tinyxml2.h"

//
using namespace std;
using namespace tinyxml2;

/*Base Class*/
class Character
{
public:
	
	// Character features
	string name;
	bool endboss;
	string boss;
	int level;
	int lifepoints;
	int experience_points;
	int attack;
	int defence;
	int attraction;
	vector<Item*> items;

	//
	virtual void message() = 0;
	virtual void parseXMLElement(XMLElement *xmlnode);

private:
};
#endif /* _CHARACTER_H_ */