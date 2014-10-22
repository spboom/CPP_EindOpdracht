#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

//
#include <iostream>
#include <string>
#include <sstream>

//
#include "GameState.h"

//
using namespace std;

class MainMenuState : public GameState
{
public:
	virtual void update(int dt);
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "MENU"; };

	//void quitGame(int exitcode);

private:

	//static void userInputHandler();
	//static void userOutputHandler(string input);
};
#endif /* _MENUSTATE_H_ */