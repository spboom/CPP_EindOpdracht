#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
#include "tinyxml2.h"

//
using namespace tinyxml2;

class Player : public Character
{
public:
	Player();
	virtual ~Player();
	
	void parseXMLElement(XMLElement *xmlelement);
};
#endif /* _PLAYER_H_ */
