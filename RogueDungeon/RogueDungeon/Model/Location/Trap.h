#ifndef _TRAP_H_
#define _TRAP_H_

//
#include <vector>
#include "tinyxml2.h"

//
#include "../GameObject.h"

//
using namespace std;
using namespace tinyxml2;

class Trap : public GameObject
{
public:
	Trap();
	virtual ~Trap();
	void parseXML(XMLElement *xmlelement);

	int damage;
	string name;

private:
};
#endif /* _TRAP_H_ */
