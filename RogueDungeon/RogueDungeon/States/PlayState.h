#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>
#include "../Model/Location/Room.h"
#include "../Library/stdafx.h"
#include "../Model/Character/Player.h"


//
#include "GameState.h"
#include "../Model/Dungeon.h"

class PlayState : public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onReEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "PLAY"; };
	PlayState();
	virtual ~PlayState();
	void setText();
private:
	void drawMap();
	void OutputHandler(string input);
	Dungeon* dungeon;
	int level;
	Player* player;
};
#endif /* _PLAYSTATE_H_ */