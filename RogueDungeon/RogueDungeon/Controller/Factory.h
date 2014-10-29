#ifndef _FACTORY_H_
#define _FACTORY_H_

//
#include "../Model/Location/Room.h";

//
using namespace std;

class Factory
{
public:
	static Factory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Factory();
			return s_pInstance;
		}
		return s_pInstance;
	}
	Room* createDungeon(int width, int height);
	void roomCharacteristics();
private:
	Factory();
	~Factory();
	static Factory* s_pInstance;
	vector<string>* characteristics;
};
typedef Factory TheFactory;
#endif /* _CONTROLLER_H_ */

