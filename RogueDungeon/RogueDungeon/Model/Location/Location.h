#ifndef _LOCATION_H_
#define _LOCATION_H_

//
#include "../GameObject.h"

//
#include "tinyxml2.h"
#include <vector>

//
using namespace std;
using namespace tinyxml2;

/* BASE CLASS */
class Location : public GameObject
{
public:
	Location();
	virtual ~Location();
	
	//
	virtual void parseXMLElement(XMLElement *xmlnode);
private:
};
#endif /* _LOCATION_H_ */
