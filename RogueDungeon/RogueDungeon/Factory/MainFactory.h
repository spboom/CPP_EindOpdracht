#ifndef _FACTORY_H_
#define _FACTORY_H_

//
#include "../Model/Location/Room.h";
#include "tinyxml2.h"

//
using namespace std;
using namespace tinyxml2;

class MainFactory
{
public:
	MainFactory();
	~MainFactory();
	static MainFactory* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new MainFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}
	Room* createDungeon(int width, int height);
	void fillAllVectors();
	void getVectorContent(vector<string> *sort);
	string getRandomVectorItems(vector<string> *random);
	vector<string>* getCharacteristicsVector();
	vector<string>* getCharacters();

	virtual void parseXML(string xmlPath);
private:
	static MainFactory* s_pInstance;
};
typedef MainFactory TheFactory;
#endif /* _CONTROLLER_H_ */

