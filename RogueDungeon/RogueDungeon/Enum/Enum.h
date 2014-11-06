#ifndef _ENUM_H_
#define _ENUM_H_

//
#include <string>

//

//
using namespace std;

class Enum
{
public:
	enum Items {
		ITEM, CONSUMABLE_ITEM, USABLE_ITEM, WEARABLE_ITEM
	};
	enum Locations {
		ROOM, HALLWAY, STAIRCASE, TRAP
	};
	int getItemEnum(string itemname);
	int getLocationEnum(string locationname);
private:
};
#endif /* _ENUM_H_ */