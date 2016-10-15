#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	choice = 0;
	difficultySetting = 1;
}


Menu::~Menu()
{
}

//get
int Menu::getDif() { return difficultySetting; }

//set
void Menu::getDif(int _difficulty) { difficultySetting = _difficulty; }



void Menu::mainMenu()
{
	Console::Clear();
	//choice = 0;
	while (true)
	{
		if (choice == 0)
		{
			Console::SetWindowSize(120, 38);
			Console::SetBufferSize(120, 38);
			Console::SetWindowSize(120, 38);

			Console::Clear();

			Console::ForegroundColor(Yellow);
			cout << "      ___           ___           ___           ___           ___           ___     ";
			cout << "\n     /\\  \\         /\\  \\         /\\  \\         /\\__\\         /\\  \\         /\\__\\    ";
			cout << "\n    /::\\  \\       /::\\  \\       /::\\  \\       /::|  |       /::\\  \\       /::|  |   ";
			cout << "\n   /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:|:|  |      /:/\\:\\  \\     /:|:|  |   ";
			cout << "\n  /::\\~\\:\\  \\   /::\\~\\:\\  \\   /:/  \\:\\  \\   /:/|:|__|__   /::\\~\\:\\  \\   /:/|:|  |__ ";
			cout << "\n /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/__/ \\:\\__\\ /:/ |::::\\__\\ /:/\\:\\ \\:\\__\\ /:/ |:| /\\__\\\"";
			cout << "\n \\/__\\:\\/:/  / \\/__\\:\\/:/  / \\:\\  \\  \\/__/ \\/__/~~/:/  / \\/__\\:\\/:/  / \\/__|:|/:/  /";
			cout << "\n      \\::/  /       \\::/  /   \\:\\  \\             /:/  /       \\::/  /      |:/:/  / ";
			cout << "\n       \\/__/        /:/  /     \\:\\  \\           /:/  /        /:/  /       |::/  /  ";
			cout << "\n                   /:/  /       \\:\\__\\         /:/  /        /:/  /        /:/  /   ";
			cout << "\n                   \\/__/         \\/__/         \\/__/         \\/__/         \\/__/    ";




			Console::ForegroundColor(Gray);
			Console::SetCursorPosition(0, Console::WindowHeight() / 2 - 5);
			cout << "    1. Play";
			cout << "\n    2. Instructions";
			cout << "\n    3. Difficulty selection";
			cout << "\n    4. Highscores";
			choice++;
		}

		if (GetAsyncKeyState('1'))
		{
			break;
		}
		if (GetAsyncKeyState('2'))
		{
			controls();
			choice = 0;
		}
		if (GetAsyncKeyState('3'))
		{
			difficulty();
			choice = 0;
		}
		if (GetAsyncKeyState('4'))
		{
			displayHighscores();
			choice = 0;
		}

	}
}

void Menu::controls()
{
	Console::Clear();

	Console::SetCursorPosition(0, Console::WindowHeight() / 2 - 10);
	cout << "Waka around the map to collect pellets and earn points";
	cout << "\n\nGhosts will start to chase you avoid them to stay alive.";
	cout << "\n\nCollect large pellets to earn more points.";
	cout << "\n\nUse WASD for controls";
	cout << "\n\nIf you are coming across a tight corner, try holding down the direction you want to turn";
	cout << "\n\nPress ESC anytime during gameplay to quit.";
	cout << "\n\nPress ESC to return to the main menu.";

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			return;
	}
}

void Menu::difficulty()
{
	choice = 0;

	difficultySetting = 0;

	Console::Clear();
	while (true)
	{
		if (choice == 0)
		{

			Console::SetCursorPosition(0, Console::WindowHeight() / 2 - 8);
			cout << "1. Easy\n Has less twists and turns with more openings to breakaway from ghosts.";
			cout << "\n\n2. Normal\n Squares. Just squares...";
			cout << "\n\n4. Impossible\n This level has dots on one way areas with no exit. You have to really try hard to finish this level. We had to skip a level just to show you how much harder it is.";
			cout << "\n\nPress ESC to return to the main menu";
			choice++;
		}

		Console::Lock(true);

		if (GetAsyncKeyState('1'))
		{
			if (difficultySetting != 1)
			{
				difficultySetting = 1;
				cout << "\n\nDifficulty set to easy. Press ESC to return to the main menu.";
			}
		}
		if (GetAsyncKeyState('2'))
		{
			if (difficultySetting != 2)
			{
				difficultySetting = 2;
				cout << "\n\nDifficulty set to normal. Press ESC to return to the main menu.";
			}
		}
		if (GetAsyncKeyState('4'))
		{
			if (difficultySetting != 3)
			{
				difficultySetting = 3;
				cout << "\n\nDifficulty set to impossible. Press ESC to return to the main menu. And good luck...";
			}
		}

		Console::ForegroundColor(Gray);
		Console::Lock(false);
		

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			if (difficultySetting == 0)
			{
				cout << "\nTry again, make sure you pick a difficulty before exiting.";
			}
			else
				return;
		}
		Sleep(50);
	}
}

void Menu::displayHighscores()
{
	Console::Clear();
	
	ifstream highscoreInput;

	highscoreInput.open("Highscores.bin", ios_base::binary);

	if (highscoreInput.is_open())
	{
		/*highscoreInput.seekg(0, ios_base::end);
		int count = (int)highscoreInput.tellg();
		highscoreInput.seekg(0, ios_base::beg);

		char text[32];
		

		while (true)
		{
			
			highscoreInput.read((char*)&)
			if (highscoreInput.eof())
				break;

			
		}*/
		highscoreInput.close();
	}
	else
	{
		//file didn't open
	}

	cout << "Press ESC to return to the main menu.";

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			return;
	}
}