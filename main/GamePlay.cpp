#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	User = new Player();
	Enemies = new Base[4];

	play = true;
	up = false;
	down = false;
	right = false;
	left = false;
	changeSymbol = 0;

	int i = 0;
	for (; i < 4; ++i)
	{
		//Enemies->SetAlive(true);
		Enemies->SetFrontColor(Blue);
	}

}

GamePlay::~GamePlay()
{
}


void GamePlay::Play()
{
	Console::CursorVisible(false);

	while (play)
	{
		Update();
		Render();
	}
}
void GamePlay::Update()
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
	changeSymbol++;
}
void GamePlay::Render()
{
	Console::Lock(true);
	Console::Clear();

	if (changeSymbol % 4 < 3)
		Player->SetSymbol('O');

	//Classic Pacman movement
	if (up)
	{
		if (changeSymbol % 4 > 2)
			Player->SetSymbol('V');
		Player->SetY(Player->GetY() - 1);
	}
	if (down)
	{
		if (changeSymbol % 4 > 2)
			Player->SetSymbol('^');
		Player->SetY(Player->GetY() + 1);
	}
	if (left)
	{
		if (changeSymbol % 4 > 2)
			Player->SetSymbol('>');
		Player->SetX(Player->GetX() - 1);
	}
	if (right)
	{
		if (changeSymbol % 4 > 2)
			Player->SetSymbol('<');
		Player->SetX(Player->GetX() + 1);
	}

	//Display objects here
	if (Player->GetX() < 0)
		Player->SetX(0);
	else if (Player->GetX() > Console::WindowWidth() - 1)
		Player->SetX(Console::WindowWidth() - 1);
	if (Player->GetY() < 0)
		Player->SetY(0);
	else if (Player->GetY() > Console::WindowHeight() - 1)
		Player->SetY(Console::WindowHeight() - 1);
	Console::SetCursorPosition(Player->GetX(), Player->GetY());
	Console::ForegroundColor(Player->GetFrontColor());
	cout << Player->GetSymbol();
	Console::ForegroundColor(Gray);

	Console::Lock(false);
	Sleep(80);
}