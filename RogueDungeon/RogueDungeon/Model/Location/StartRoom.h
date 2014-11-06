#ifndef _STARTROOM_H_
#define _STARTROOM_H_

//
#include "Room.h"

//
using namespace std;

class StartRoom : public Room
{
public:
	StartRoom(int level);
	virtual ~StartRoom();
	virtual char getSymbol();
};


#endif /* _STARTROOM_H_ */
