#ifndef _CONSUMABLEITEM_H_
#define _CONSUMABLEITEM_H_

//
#include "tinyxml2.h"
#include <string>

//
#include "Item.h"

//
using namespace std;
using namespace tinyxml2;

/*Derived class Enemy from Character*/
class ConsumableItem : public Item
{
public:
	ConsumableItem();
	virtual ~ConsumableItem();
	virtual void message();
	void parseXMLElement(XMLElement *xmlelement);
private:
};
#endif /* _CONSUMABLE_H_ */
