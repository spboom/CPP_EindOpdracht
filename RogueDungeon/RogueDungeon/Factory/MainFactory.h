#ifndef _MAINFACTORY_H_
#define _MAINFACTORY_H_

//
#include <random>

//
#include "../Model/Location/Room.h";
#include "../Model/Location/Hallway.h"
#include "tinyxml2.h"
#include "../Model/Dungeon.h"
#include "../Model/Location/StartRoom.h"
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

	vector<vector<Room*>> createDungeonFloor(int* entranceXpos, int* entranceYpos, int width, int height, int level);
	int moveOneToGoal(int* current, int goal);
	Directions::Direction moveXOneToGoal(int* current, int goal);
	Directions::Direction moveYOneToGoal(int* current, int goal);
	void createpath(vector<vector<Room*>>* floor, int fromX, int fromY, int toX, int toY, bool shouldBreak);

	random_device dev;
	uniform_int_distribution<int> widthDist;
	uniform_int_distribution<int> heightDist;
	uniform_int_distribution<int> depthDist;

	vector<string>* characteristics;
protected:
	default_random_engine dre;
	uniform_int_distribution<int> chance = uniform_int_distribution<int>(0, 100);
};
typedef MainFactory TheFactory;
#endif /* _MAINFACTORY_H_ */

