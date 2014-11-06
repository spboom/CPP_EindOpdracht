#ifndef _USABLEITEM_H_
#define _USABLEITEM_H_

//
#include "tinyxml2.h"
#include <string>

//
#include "Item.h"

//
using namespace std;
using namespace tinyxml2;

/*Derived class Enemy from Character*/
class UsableItem : public Item
{
public:
	UsableItem();
	virtual ~UsableItem();
	virtual void message();
	void parseXMLElement(XMLElement *xmlelement);
private:
};
#endif /* _USABLE_H_ */
