#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	User = new Player(Console::WindowWidth() / 2, Console::WindowHeight() / 4 * 3, 'O', Yellow);
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
		User->SetSymbol('O');

	//Classic Pacman movement
	if (up)
	{
		if (changeSymbol % 4 > 2)
			User->SetSymbol('V');
		User->SetY(User->GetY() - 1);
	}
	if (down)
	{
		if (changeSymbol % 4 > 2)
			User->SetSymbol('^');
		User->SetY(User->GetY() + 1);
	}
	if (left)
	{
		if (changeSymbol % 4 > 2)
			User->SetSymbol('>');
		User->SetX(User->GetX() - 1);
	}
	if (right)
	{
		if (changeSymbol % 4 > 2)
			User->SetSymbol('<');
		User->SetX(User->GetX() + 1);
	}

	//Display objects here
	if (User->GetX() < 0)
		User->SetX(0);
	else if (User->GetX() > Console::WindowWidth() - 1)
		User->SetX(Console::WindowWidth() - 1);
	if (User->GetY() < 0)
		User->SetY(0);
	else if (User->GetY() > Console::WindowHeight() - 1)
		User->SetY(Console::WindowHeight() - 1);
	Console::SetCursorPosition(User->GetX(), User->GetY());
	Console::ForegroundColor(User->GetFrontColor());
	cout << User->GetSymbol();
	Console::ForegroundColor(Gray);

	Console::Lock(false);
	Sleep(80);
}