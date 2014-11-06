#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include "Staircase.h"
#include "Directions.h"

//

//

Staircase::Staircase(Room* from, Room* to) : Hallway(from, to, Directions::Down)
{
}


Staircase::~Staircase()
{
}
