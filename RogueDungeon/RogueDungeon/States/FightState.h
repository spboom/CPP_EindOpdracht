#ifndef _FIGHTTSSTATE_H_
#define _FIGHTTSSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>
#include "../Library/stdafx.h"

//
#include "GameState.h"
#include "../Model/Character/Enemy/Enemy.h"
#include "../Model/Character/Player.h"

class FightState : public GameState {
public:
	FightState(vector<Enemy*> enemies, Player* player);
	virtual ~FightState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onReEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "FIGHT"; };
private:
	void step(bool attack, string aditionalLine);
	void step(bool attack);
	vector<Enemy*> enemies;
	Player* player;
	void OutputHandler(string input);

	vector<string> lines;
};
#endif /* _FIGHTTSSTATE_H_ */