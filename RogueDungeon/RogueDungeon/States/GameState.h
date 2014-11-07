#ifndef GAMESTATE_H_
#define GAMESTATE_H_

//

//
#include <string>

//
using namespace std;

class GameState
{
public:
	GameState();
	virtual ~GameState();
	virtual void update();
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
protected:
	virtual void OutputHandler(string input);
};
#endif /* GAMESTATE_H_ */
