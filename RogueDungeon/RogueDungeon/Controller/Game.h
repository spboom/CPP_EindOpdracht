#ifndef _GAME_H_
#define _GAME_H_

//
#include <string>

//
#include "GameStateMachine.h"
#include "../Model/Character/Player.h"
#include "../Model/Character/Enemy/Enemy.h"

//
using namespace std;

class Game
{
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	// simply set the running variable to true
	bool init(string title, int width, int height); //{ m_bRunning = true; }
	void render();
	void update();
	void handleEvents();
	void quitGame(int exitcode);
	void clean();
	void cleanScreen();
	GameStateMachine* getStateMachine();
	void goToPlay();
	void goToMainMenu();
	void goToCredits();
	void goToFight(vector<Enemy*> enemies, Player* player);

	// a function to access the private running variable
	bool running() { return m_bRunning; }
private:
	Game();
	virtual ~Game();
	static Game* s_pInstance;
	bool m_bRunning;
	GameStateMachine* m_pGameStateMachine;
	void setWindowTitle(string title);
	void setWindowSize(int width, int height);
	void setWindowCenterScreen(int width, int height);
};
typedef Game TheGame;
#endif /* defined(GAME_H_) */