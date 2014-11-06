#ifndef _CREDITSSTATE_H_
#define _CREDITSSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>
#include "../Library/stdafx.h"

//
#include "GameState.h"

class CreditsState : public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "CREDITS"; };
private:
	void OutputHandler(string input);
};
#endif /* _CREDITSSTATE_H_ */