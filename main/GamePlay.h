#pragma once

#include "stdafx.h"
#include "Base.h"



class GamePlay
{
	Base* Player = new Base(Console::WindowWidth() / 2, Console::WindowHeight() / 2, true, '@', Black, Yellow);

	Base* Enemies = new Base[4];
	bool play = true;
	bool up;
	bool down;
	bool right;
	bool left;

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
		if (GetAsyncKeyState('W'))
		{
			up = true;
			down = false;
			right = false;
			left = false;
		}
		else if (GetAsyncKeyState('S'))
		{
			up = false;
			down = true;
			right = false;
			left = false;
		}
		else if (GetAsyncKeyState('A'))
		{
			left = true;
			up = false;
			down = false;
			right = false;
		}
		else if (GetAsyncKeyState('D'))
		{
			right = true;
			up = false;
			down = false;
			left = false;
		}
	}
	void Render()
	{
		Console::Lock(true);
		Console::Clear();

		if (up)
			Player->SetY(Player->GetY() - 1);
		if (down)
			Player->SetY(Player->GetY() + 1);
		if (left)
			Player->SetX(Player->GetX() - 1);
		if (right)
			Player->SetX(Player->GetX() + 1);

		//Display objects here
		if (Player->GetX() < 0)
			Player->SetX(0);
		else if (Player->GetX() > Console::WindowWidth() - 1)
			Player->SetX(Console::WindowWidth() - 1);
		if (Player ->GetY() < 0)
			Player->SetY(0);
		else if (Player->GetY() > Console::WindowHeight() - 1)
			Player->SetY(Console::WindowHeight() - 1);
		Console::SetCursorPosition(Player->GetX(), Player->GetY());
		cout << Player->GetSymbol();
		/*Player->SetX(Player->GetX() + 1);
		Player->SetY(Player->GetY() + 1);
		Console::SetCursorPosition(Player->GetX(), Player->GetY());
		cout << Player->GetSymbol();*/

		Console::Lock(false);
		Sleep(100);
	}
};