//#ifndef _FACTORY_H_
//#define _FACTORY_H_
//
////
//#include "../Model/Location/Room.h";
//#include <random>
//
////
//using namespace std;
//
//class Factory
//{
//public:
//	static Factory* Instance()
//	{
//		if (s_pInstance == 0)
//		{
//			s_pInstance = new Factory();
//			return s_pInstance;
//		}
//		return s_pInstance;
//	}
//	Room* createDungeon(int width, int height);
//	void roomCharacteristics();
//	vector<vector<vector<Room*>>> createDungeon(int width, int height, int depth);
//	void Factory::clean();
//
//private:
//	Factory();
//	~Factory();
//
//	vector<vector<Room*>> createDungeonFloor(int* entranceXpos, int* entranceYpos, int width, int height);
//	int moveOneToGoal(int* current, int goal);
//	Directions moveXOneToGoal(int* current, int goal);
//	Directions moveYOneToGoal(int* current, int goal);
//
//	random_device dev;
//	default_random_engine dre;
//	uniform_int_distribution<int> widthDist;
//	uniform_int_distribution<int> heightDist;
//	uniform_int_distribution<int> depthDist;
//
//	vector<string>* characteristics;
//
//	static Factory* s_pInstance;
//};
//typedef Factory TheFactory;
//#endif /* __H_ */
//
