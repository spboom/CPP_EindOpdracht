#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>
#include <stdio.h>

//
#include "GameState.h"

bool GameState::onExit()
{
	delete this;
	return true;
}