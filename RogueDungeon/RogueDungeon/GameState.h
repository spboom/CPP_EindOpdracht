#ifndef GAMESTATE_H_
#define GAMESTATE_H_

//
#include <string>

class GameState
{
public:
	GameState() {}
	~GameState() {}
	virtual void update(int dt) = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};
#endif /* GAMESTATE_H_ */
