#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>
#include "stdafx.h"

//
#include "GameState.h"

class PlayState : public GameState
{
public:

	virtual void update(int dt);
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "PLAY"; };
private:

};
#endif /* _PLAYSTATE_H_ */