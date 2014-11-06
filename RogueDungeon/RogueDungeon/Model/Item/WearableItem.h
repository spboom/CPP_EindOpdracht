#ifndef _WEARABLEITEM_H_
#define _WEARABLEITEM_H_

//
#include "tinyxml2.h"
#include <string>

//
#include "Item.h"

//
using namespace std;
using namespace tinyxml2;

/*Derived class Enemy from Character*/
class WearableItem : public Item
{
public:
	WearableItem();
	virtual ~WearableItem();
	virtual void message();
	void parseXMLElement(XMLElement *xmlelement);
private:
};
#endif /* _USABLE_H_ */
