#ifdef _WIN32
// RogueDungeon.cpp : Defines the entry point for the console application.
// Check for memory leaks. Put snippet in beginning of program: _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#define _CRTDBG_MAP_ALLOC
#endif

#ifdef __unix__
#endif

//
#include "stdafx.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <windows.h>
#include <strsafe.h>
#include <tchar.h>
#include <string>
#include <wincon.h>
#include <conio.h>

//
#include "Game.h"
#include "GameStateMachine.h"
#include "../States/MainMenuState.h"
#include "../States/PlayState.h"
#include "../States/CreditsState.h"
#include "InputHandler.h"

// 
Game* Game::s_pInstance;
using namespace std;

bool Game::init(string title, int width, int height) {
	// attempt to initialize SDL
	setWindowTitle(title);
	setWindowSize(width, height);
	setWindowCenterScreen(width, height);

	m_bRunning = true; // everything inited successfully, start the main loop

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());

	return true;
}

void Game::update() {}

void Game::render() {
	m_pGameStateMachine->render();
}

void Game::clean() {
	//std::cout << "cleaning game\n";
	system("cls");
}

void Game::handleEvents() {}

GameStateMachine* Game::getStateMachine() {

	return m_pGameStateMachine;
}

void Game::quitGame(int exitcode)  {
	exit(exitcode);
}

std::wstring s2ws(const std::string& s) {
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void Game::setWindowTitle(string title) {
	std::wstring stemp = s2ws(title);
	LPCWSTR result = stemp.c_str();

	TCHAR szOldTitle[MAX_PATH];
	TCHAR szNewTitle[MAX_PATH];
	// Save current console title.
	if (GetConsoleTitle(szOldTitle, MAX_PATH))
	{
		// Build new console title string.
		StringCchPrintf(szNewTitle, MAX_PATH, result, szOldTitle);
		// Set console title to new title
		if (!SetConsoleTitle(szNewTitle))
		{
			_tprintf(TEXT("SetConsoleTitle failed (%d)\n"), GetLastError());
		}
		else
		{
			//_tprintf(TEXT("SetConsoleTitle succeeded.\n"));
		}
	}
}

void Game::setWindowSize(int width, int height) {
	_COORD coord;
	coord.X = width;
	coord.Y = height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = height - 1;
	Rect.Right = width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void Game::setWindowCenterScreen(int width, int height) {
	//Get the window console handle(isn't the right code but works for these sample
	HWND ConsoleWindow;
	ConsoleWindow = GetForegroundWindow();

	//Getting the desktop hadle and rectangule
	HWND   hwndScreen;
	RECT   rectScreen;
	hwndScreen = GetDesktopWindow();
	GetWindowRect(hwndScreen, &rectScreen);

	//Set windows size(see the width problem)
	SetWindowPos(ConsoleWindow, NULL, 0, 0, width, height, SWP_SHOWWINDOW);

	// Get the current width and height of the console
	RECT rConsole;
	GetWindowRect(ConsoleWindow, &rConsole);
	int Width = rConsole.left = rConsole.right;
	int Height = rConsole.bottom - rConsole.top;

	//caculate the window console to center of the screen	
	int ConsolePosX;
	int ConsolePosY;
	ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - Width / 2);
	ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - Height / 2);
	SetWindowPos(ConsoleWindow, NULL, ConsolePosX, ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);
}

void Game::goToPlay() {
	getStateMachine()->changeState(new PlayState());
}

void Game::goToMainMenu() {
	getStateMachine()->changeState(new MainMenuState());
}

void Game::goToCredits() {
	getStateMachine()->changeState(new CreditsState());
}