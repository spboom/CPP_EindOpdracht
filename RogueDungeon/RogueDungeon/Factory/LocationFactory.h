#ifndef _LOCATIONFACTORY_H_
#define _LOCATIONFACTORY_H_

//
#include <string>

//
#include "../Model/Character/Character.h"
#include "MainFactory.h"
#include "tinyxml2.h"
#include "../Model/Location/Room.h"
#include "../Model/Location/Hallway.h"

//
using namespace std;
using namespace tinyxml2;

/*Factory Class*/
class LocationFactory : public MainFactory
{
public:
	LocationFactory();
	virtual ~LocationFactory();
	static LocationFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new LocationFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}

	//
	vector<string> room_characteristics;
	vector<string> room_feature;
	vector<string> room_state;
	vector<string> room_trap;
	vector<string> room_exits;
	vector<string> room_items;

	//
	string type;
	string name;

	/*Factory Method*/
	vector<Location*> parseXML(string xmlPath);
	void fillRoom(Room* room);
	void fillHallway(Hallway* hallway);
	Trap* getRandomTrap();
private:
	vector<Location*> locations;
	vector<Trap*> traps;
	static LocationFactory* s_pInstance;
};
typedef LocationFactory TheLocationFactory;
#endif /* _LOCATIONFACTORY_H_ */