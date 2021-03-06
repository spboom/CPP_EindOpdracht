#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>

//
#include "Player.h"
#include "../Dungeon.h"

//
using namespace std;

Player::Player(StartRoom* room)
{
	location = room;
	maxLifepoints = lifepoints = 100;
	expNeededforLvlUp = 10;
	attackPoints = 20;
}

Player::~Player()
{
}

int Player::attack(Character* enemy)
{
	int damage = Character::attack(enemy);
	if (enemy->isDead())
	{
		addExp(enemy->maxLifepoints);
	}
	return damage;
}

int Player::getDefence()
{
	return attackPoints *0.8f;
}

void Player::parseXMLElement(XMLElement *xmlelement)
{

}

void Player::levelUp()
{
	experience_points -= expNeededforLvlUp;
	expNeededforLvlUp *= 1.5;
	MaxHp *= 1.5;
	attackPoints * 2;
	level++;
}
void Player::addExp(float exp)
{
	experience_points += exp;
	while (experience_points >= expNeededforLvlUp)
	{
		levelUp();
	}
}

void Player::useItem(Item* item)
{
	//TODO
}

bool Player::move(Directions::Direction direction)
{
	Room* room = location->getRoomInDirection(direction);
	if (room)
	{
		location = room;
		return true;
	}
	return false;
}
