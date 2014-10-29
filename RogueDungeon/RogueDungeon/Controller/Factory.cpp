//
#include <tchar.h>
#include <strsafe.h>
#include <vector>

//
#include "Factory.h"
#include "../Model/Location/Directions.h"
#include "../Controller/Controller.h"

//
Factory* Factory::s_pInstance;
using namespace std;

Factory::Factory()
{
	characteristics = new vector<string>();
}

Factory::~Factory()
{
	delete characteristics;
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

// Room
void Factory::roomCharacteristics()
{
	TheController::Instance()->xmlFileController("Inputfiles/characteristics.xml", Factory::characteristics);

	std::cout << "The contents are:";
	for (std::vector<string>::iterator it = characteristics->begin(); it != characteristics->end(); ++it)
		std::cout << ' ' << *it;
		std::cout << '\n';
}

