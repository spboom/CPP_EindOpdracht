#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>

//
#include "GameState.h"
#include "../Model/Character/Character.h"
#include "../Model/Location/Location.h"
#include "../Model//Item/Item.h"


//
using namespace std;

class MainMenuState : public GameState {
public:
	MainMenuState();
	virtual MainMenuState::~MainMenuState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onReEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "MENU"; };
private:
	void OutputHandler(string input);
	vector<Character*> characters;
	vector<Item*> items;
	vector<Location*> location;
};
#endif /* _MENUSTATE_H_ */