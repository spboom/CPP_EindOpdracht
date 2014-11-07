#ifdef _WIN32
#endif

#ifdef __unix__
#endif

//
#include <tchar.h>
#include <strsafe.h>

//
#include "GameStateMachine.h"
#include "../States/MainMenuState.h"

void GameStateMachine::pushState(GameState *pState) {
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState() {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->onExit()) {
			m_gameStates.pop_back();

			if (!m_gameStates.empty())
			{
				m_gameStates.back()->onReEnter();
			}
		}
	}
}

void GameStateMachine::changeState(GameState *pState) {
	if (!m_gameStates.empty()) {

		if (m_gameStates.back()->getStateID() == pState->getStateID())
			return; // do nothing

		if (m_gameStates.back()->onExit()) {

			m_gameStates.pop_back();
		}
	}
	// push back our new state
	m_gameStates.push_back(pState);
	// initialise it
	m_gameStates.back()->onEnter();
}

void GameStateMachine::update() {
	if (!m_gameStates.empty())
		m_gameStates.back()->update();
}

void GameStateMachine::render() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->render();
	}
}

void GameStateMachine::backToMenu()
{
	while (!m_gameStates.empty())
	{
		popState();
	}
	pushState(new MainMenuState());
}

GameStateMachine::GameStateMachine() {}

GameStateMachine::~GameStateMachine()
{
	while (!m_gameStates.empty())
	{
		popState();
	}
}
