#pragma once

#include "stdafx.h"
#include "Base.h"



class GamePlay
{
	Base* Player = new Base(Console::WindowWidth() / 2, Console::WindowHeight() / 2, true, '@', Black, Yellow);
	
	Base* Enemies = new Base[4];
	bool play = true;

public:
	GamePlay();

	~GamePlay();

	
	void Play()
	{
		while (play)
		{
			Update();
			Render();
		}
	}
	void Update()
	{
		
	}
	void Render()
	{
		Console::Lock(true);
		Console::Clear();
		//Display objects here
		Console::SetCursorPosition(Player->GetX(), Player->GetY());
		cout << Player->GetSymbol();

		Console::Lock(false);
		Sleep(10);
	}

};