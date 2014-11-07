#ifndef _ITEMFACTORY_H_
#define _ITEMFACTORY_H_

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
class ItemFactory : public MainFactory
{
public:
	ItemFactory();
	virtual ~ItemFactory();
	static ItemFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new ItemFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}

	/*Factory Method*/
	vector<Item*> parseXML(string xmlPath);
	void fillRoom(Room* room);
private:
	vector<Item*> items;
	static ItemFactory* s_pInstance;
};
typedef ItemFactory TheItemFactory;
#endif /* _ITEMFACTORY_H_ */