#ifndef _CHARACTER_H_
#define _CHARACTER_H_

// 
#include "../Item/Item.h"
#include "../GameObject.h"


//
#include <vector>
#include <string>
#include "tinyxml2.h"

//
using namespace std;
using namespace tinyxml2;

/*Base Class*/
class Character : public GameObject
{
public:
	Character();
	virtual ~Character();

	// Character features
	string name;
	int level;
	int lifepoints;
	int attackPoints;
	int defencePoints;
	vector<Item*> items;

	//
	virtual void message() = 0;
	virtual void parseXMLElement(XMLElement *xmlnode);

	int hit(int attackPoints);
	int attack(Character* character);

private:
};
#endif /* _CHARACTER_H_ */
