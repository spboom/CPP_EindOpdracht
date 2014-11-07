#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
#include "tinyxml2.h"
#include "../Location/StartRoom.h"
#include "Enemy\Enemy.h"

//
using namespace tinyxml2;

class Player : public Character
{
public:
	Player(StartRoom* room);
	virtual ~Player();

	virtual void message() { };
	void parseXMLElement(XMLElement *xmlelement);
	Room* location;

	void move(Directions::Direction direction);
	void addExp(float exp);
	void useItem(Item* item);
private:
	float expNeededforLvlUp;
	void levelUp();
	float observation;
	float experience_points;

	int MaxHp;

};
#endif /* _PLAYER_H_ */
