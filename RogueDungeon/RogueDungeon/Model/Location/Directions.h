#ifndef _DIRECTIONS_H_
#define _DIRECTIONS_H_

//

//
#include <string>

//
using namespace std;

class Directions {
public:
	enum Direction
	{
		North = 1, South, East, West, Up, Down
	};
	Directions();
	virtual ~Directions();

	static string ToString(Direction direction)
	{
		switch (direction)
		{
		case Directions::North:
			return "noord";
		case Directions::South:
			return "zuid";
		case Directions::East:
			return "oost";
		case Directions::West:
			return "west";
		case Directions::Up:
			return "omhoog";
		case Directions::Down:
			return "omlaag";
		default:
			return "";
		}
	}
private:
};
#endif /* _DIRECTIONS_H_ */