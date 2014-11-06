#ifndef _MAINFACTORY_H_
#define _MAINFACTORY_H_

//
#include <random>

//
#include "../Model/Location/Room.h";
#include "tinyxml2.h"
#include "../Model/Dungeon.h"

//
using namespace std;
using namespace tinyxml2;

class MainFactory
{
public:
	MainFactory();
	virtual ~MainFactory();
	static MainFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new MainFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void fillAllVectors();
	string getRandomVectorItems(vector<string> *random);
	Dungeon* createDungeon(int width, int height, int depth);
	void clean();
	void fillRoom(Room* room);
private:
	static MainFactory* s_pInstance;

	vector<vector<Room*>> createDungeonFloor(int* entranceXpos, int* entranceYpos, int width, int height);
	int moveOneToGoal(int* current, int goal);
	Directions::Direction moveXOneToGoal(int* current, int goal);
	Directions::Direction moveYOneToGoal(int* current, int goal);

	random_device dev;
	default_random_engine dre;
	uniform_int_distribution<int> widthDist;
	uniform_int_distribution<int> heightDist;
	uniform_int_distribution<int> depthDist;

	vector<string>* characteristics;
};
typedef MainFactory TheFactory;
#endif /* _MAINFACTORY_H_ */

