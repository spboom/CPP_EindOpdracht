#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>

//
#include "GameState.h"
#include "../Model/Character/Character.h"
#include "../Model//Item/Item.h"


//
using namespace std;

class MainMenuState : public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "MENU"; };
private:
	MainMenuState::~MainMenuState();
	void OutputHandler(string input);
	vector<Character*> characters;
	vector<Item*> items;
};
#endif /* _MENUSTATE_H_ */