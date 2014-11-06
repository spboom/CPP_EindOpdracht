//
#include <tchar.h>
#include <strsafe.h>
#include <vector>
#include "tinyxml2.h"

//
#include "MainFactory.h"
#include "../Model/Location/Directions.h"
#include "../Controller/Controller.h"

//
MainFactory* MainFactory::s_pInstance;

//
using namespace std;
using namespace tinyxml2;

MainFactory::MainFactory()
{
	
}

MainFactory::~MainFactory()
{
	
}

void MainFactory::fillAllVectors()
{
	// TheController::Instance()->xmlFileController("Inputfiles/Room/room_characteristics.xml", MainFactory::characteristics);
}

void MainFactory::getVectorContent(vector<string> *sort)
{
	std::cout << "The contents are:";
	for (std::vector<string>::iterator it = sort->begin(); it != sort->end(); ++it)
		std::cout << ' ' << *it + ','; std::cout << '\n';
}

string MainFactory::getRandomVectorItems(vector<string> *random)
{
	std::vector<string>::iterator randIt = random->begin();
	std::advance(randIt, std::rand() % random->size());
	//std::cout << "Random selection: " << *randIt << std::endl;
	return *randIt;
}

Room* createDungeon(int width, int height)
{
	Room **rooms = new Room*[width];

	for (int x = 0; x < width; x++)
	{
		rooms[x] = new Room[height];
	}

	/*int connected = 0;
	vector<Room> notConnectedRooms = vector<Room>();

	while (connected < width*height)
	{
		rooms[0][0].connected = true;
		connected++;
	}*/

	return nullptr;
}

//Room linkRoom(Room* connected, Room* room, Directions direction)
//{
//	Hallway* hall = new Hallway();
//}

void MainFactory::parseXML(string xmlPath)
{

}
