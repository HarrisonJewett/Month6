// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GamePlay.h"


int main()
{
	Console::CursorVisible(false);

	bool play = true;

	while (play)
	{
		GamePlay gp;
		gp.Play();
		play = gp.gameOver();
	}
    return 0;
}