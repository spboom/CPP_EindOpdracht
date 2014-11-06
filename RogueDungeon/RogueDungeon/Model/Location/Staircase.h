#ifndef _STAIRCASE_H_
#define _STAIRCASE_H_

//
#include "Hallway.h"
#include "Directions.h"

//

//

class Staircase : public Hallway
{
public:
	Staircase(Room* from, Room* to);
	virtual ~Staircase();
};
#endif /* _STAIRCASE_H_ */
