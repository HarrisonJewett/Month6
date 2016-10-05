#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	/*Player->SetFrontColor(Yellow);
	Player->SetX(Console::WindowWidth() / 2);
	Player->SetY(Console::WindowHeight() / 2);
	Player ->SetAlive*/

	int i = 0;
	for (; i < 4; ++i)
	{
		Enemies->SetAlive(true);
		Enemies->SetFrontColor(Blue);
	}

}

GamePlay::~GamePlay()
{
}
