#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include "StartRoom.h"

//
using namespace std;

StartRoom::StartRoom(int level) :Room(level)
{}

StartRoom::~StartRoom()
{}

char StartRoom::getSymbol()
{
	return 'S';
}
