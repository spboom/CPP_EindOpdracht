#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <iostream>
#include <string>
#include <sstream>
#include "stdafx.h"

//
#include "Game.h"
#include "PlayState.h"
#include "InputHandler.h"


void PlayState::update(int dt) {}

void PlayState::render() {}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";

	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";

	return true;
}