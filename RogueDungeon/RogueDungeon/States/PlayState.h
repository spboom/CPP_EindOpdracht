#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>
#include "../Model/Location/Room.h"
#include "../Library/stdafx.h"

//
#include "GameState.h"

class PlayState : public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "PLAY"; };
	PlayState();
	virtual ~PlayState();
private:
	void drawMap();
	void OutputHandler(string input);
	vector<vector<vector<Room*>>> dungeon;
	int level;
};
#endif /* _PLAYSTATE_H_ */