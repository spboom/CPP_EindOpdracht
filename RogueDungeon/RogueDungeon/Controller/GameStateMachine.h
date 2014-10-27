#ifndef _GAMESTATEMACHINE_H_
#define _GAMESTATEMACHINE_H_

//
#include "../States/GameState.h"

//
#include <vector>

using namespace std;

class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void update(int dt);
	void render();
private:
	std::vector<GameState*> m_gameStates;
};
#endif /* _GAMESTATEMACHINE_H_ */