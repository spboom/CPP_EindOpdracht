#ifndef _CHARACTERFACTORY_H_
#define _CHARACTERFACTORY_H_

//
#include <string>

//
#include "../Model/Character/Character.h"
#include "MainFactory.h"
#include "tinyxml2.h"

//
using namespace std;
using namespace tinyxml2;

/*Factory Class*/
class CharacterFactory : public MainFactory
{
public:
	CharacterFactory();
	virtual ~CharacterFactory();
	static CharacterFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new CharacterFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}

	/*Factory Method*/
	vector<Enemy*> parseXML(string xmlPath);
	void fillRoom(Room* room);
	Enemy* CharacterFactory::getRandomCharacter();
private:
	vector<Enemy*> characters;
	static CharacterFactory* s_pInstance;
};
typedef CharacterFactory TheCharacterFactory;
#endif /* _CHARACTERFACTORY_H_ */