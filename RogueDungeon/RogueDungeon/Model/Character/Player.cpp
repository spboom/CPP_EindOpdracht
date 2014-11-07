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
}

Player::~Player()
{
}

void Player::parseXMLElement(XMLElement *xmlelement)
{

}

void Player::levelUp()
{
	experience_points -= expNeededforLvlUp;
	expNeededforLvlUp *= 1.5;
	MaxHp *= 1.5;
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

bool Player::move(Directions::Direction direction)
{
	vector<vector<Room*>> floor = dungeon->getFloor(location->getLevel());
	for (int y = 0; y < floor.size(); y++)
	{
		for (int x = 0; x < floor[y].size(); x++)
		{
			location = floor[y][x];
			if (direction == Directions::Direction::North)
			{
				if (location->hasHallway(Directions::East))
				{
					
				}
				else if (location->hasHallway(Directions::South))
				{

				}
				else if (location->hasHallway(Directions::West))
				{

				}
			}
			else if (direction == Directions::Direction::East)
			{
				if (location->hasHallway(Directions::North))
				{

				}
				else if (location->hasHallway(Directions::South))
				{

				}
				else if (location->hasHallway(Directions::West))
				{

				}
			}
			else if (direction == Directions::Direction::South)
			{
				if (location->hasHallway(Directions::North))
				{

				}
				else if (location->hasHallway(Directions::East))
				{

				}
				else if (location->hasHallway(Directions::West))
				{

				}
			}
			else if (direction == Directions::Direction::West)
			{
				if (location->hasHallway(Directions::North))
				{

				}
				else if (location->hasHallway(Directions::East))
				{

				}
				else if (location->hasHallway(Directions::South))
				{

				}
			}
		}
	}
	return true;
}
