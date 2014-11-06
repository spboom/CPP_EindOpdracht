#ifndef _ITEM_H_
#define _ITEM_H_

// 

//
#include <vector>
#include <string>
#include "tinyxml2.h"
#include "../GameObject.h"
//
using namespace std;
using namespace tinyxml2;

/*Base Class*/
class Item :public GameObject
{
public:
	// Item variables
	string name;
	string type;

	//
	void message();
	virtual void parseXMLElement(XMLElement *xmlnode);

private:
};
#endif /* _ITEM_H_ */
