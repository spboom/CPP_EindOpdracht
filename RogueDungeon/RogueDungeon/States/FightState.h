#ifndef _FIGHTTSSTATE_H_
#define _FIGHTTSSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>
#include "../Library/stdafx.h"

//
#include "GameState.h"

class FightState : public GameState {
public:
	FightState();
	virtual ~FightState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "FIGHT"; };
private:
	void OutputHandler(string input);
};
#endif /* _FIGHTTSSTATE_H_ */