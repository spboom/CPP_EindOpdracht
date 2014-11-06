#ifndef _LOCATIONFACTORY_H_
#define _LOCATIONFACTORY_H_

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
class LocationFactory : public MainFactory
{
public:
	LocationFactory();
	~LocationFactory();
	static LocationFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new LocationFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}

	/*Factory Method*/
	void parseXML(string xmlPath);

private:
	static LocationFactory* s_pInstance;
};
typedef LocationFactory TheLocationFactory;
#endif /* _LOCATIONFACTORY_H_ */