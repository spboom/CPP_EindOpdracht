#ifndef _DIRECTIONS_H_
#define _DIRECTIONS_H_

//

//

//
class Directions {
public:
	enum Direction
	{
		North = 1, South, East, West, Up, Down
	};
	Directions();
	virtual ~Directions();
private:
};
#endif /* _DIRECTIONS_H_ */