#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	//Adding two lines for displaying score and "Press ESC to exit"
	Console::SetWindowSize(30, 38);
	Console::SetBufferSize(30, 38);

	User = new Player(Console::WindowWidth() / 2, Console::WindowHeight() / 5 * 3 + 1, 'O', Yellow);
	Ghosts = new Enemy[4];

	//Walls xSize
	walls = new Walls**[30];
	for (int x = 0; x < 30; x++)
	{
		//Walls ySize
		walls[x] = new Walls*[36];
		for (int y = 0; y < 36; y++)
		{
			//storing class Walls in the two dimentional array
			walls[x][y] = new Walls();
		}
	}

	play = true;
	up = false;
	down = false;
	right = false;
	left = false;
	changeSymbol = 0;
	pacmanAlive = true;
	score = 0;
	ghostMove = 0;

	int i = 0;
	for (; i < 4; ++i)
	{
		Ghosts[i].SetX(Console::WindowWidth() / 2 - (i - 1));
		Ghosts[i].SetY(Console::WindowHeight() / 2 + (i % 2));
	}
	Ghosts[0].SetFrontColor(Red);
	//Ghosts[0].SetAlive(true);
	Ghosts[1].SetFrontColor(Cyan);
	Ghosts[2].SetFrontColor(Yellow);
	Ghosts[3].SetFrontColor(Magenta);

	setUpWalls();
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
	//Getting key input for pacman movement
	if (GetAsyncKeyState('W'))
	{
		if (!walls[User->GetX()][User->GetY() - 2]->isAlive())
		{
			up = true;
			down = false;
			right = false;
			left = false;
		}
	}
	else if (GetAsyncKeyState('S'))
	{
		if (!walls[User->GetX()][User->GetY()]->isAlive())
		{
			up = false;
			down = true;
			right = false;
			left = false;
		}
	}
	else if (GetAsyncKeyState('A'))
	{
		if (!walls[User->GetX() - 1][User->GetY() + 1]->isAlive())
		{
			left = true;
			up = false;
			down = false;
			right = false;
		}
	}
	else if (GetAsyncKeyState('D'))
	{
		if (!walls[User->GetX() + 1][User->GetY() + 1]->isAlive())
		{
			right = true;
			up = false;
			down = false;
			left = false;
		}
	}
}
void GamePlay::Render()
{
	Console::Lock(true);
	//Console::Clear();
	Console::SetCursorPosition(0, 0);
	cout << "Lives x" << User->GetLives() << "   Score: " << score;
		
	Console::SetCursorPosition(0, Console::WindowHeight() - 1);
	cout << "Press ESC to exit";

	//Changing animations for Ghost idle
	if (score < 200)
	{
		if (changeSymbol % 15 == 7)
		{
			for (int i = 0; i < 4; i++)
			{
				Console::SetCursorPosition(Ghosts[i].GetX(), Ghosts[i].GetY());
				cout << ' ';
				if (!Ghosts[i].GetAlive() && Ghosts[i].GetY() == Console::WindowHeight() / 2)
					Ghosts[i].SetY(Ghosts[i].GetY() + 1);
				else if (!Ghosts[i].GetAlive())
					Ghosts[i].SetY(Ghosts[i].GetY() - 1);
			}
		}
	}

	//Classic Pacman movement and animation
	if (changeSymbol % 6 < 3)
		User->SetSymbol('O');
	Console::SetCursorPosition(User->GetX(), User->GetY());
	cout << ' ';
	if (up)
	{
		if (walls[User->GetX()][User->GetY()])
		{

		}
		if (changeSymbol % 6 > 2)
			User->SetSymbol('V');
		User->SetY(User->GetY() - 1);
	}
	if (down)
	{
		if (changeSymbol % 6 > 2)
			User->SetSymbol('^');
		User->SetY(User->GetY() + 1);
	}
	if (left)
	{
		if (changeSymbol % 6 > 2)
			User->SetSymbol('>');
		User->SetX(User->GetX() - 1);
	}
	if (right)
	{
		if (changeSymbol % 6 > 2)
			User->SetSymbol('<');
		User->SetX(User->GetX() + 1);
	}
	changeSymbol++;

	//Checking for console window size
	//Won't need after walls are set up
	if (User->GetX() < 0)
	{
		User->SetSymbol('O');
		User->SetX(0);
	}
	else if (User->GetX() > Console::WindowWidth() - 1)
	{
		User->SetSymbol('O');
		User->SetX(Console::WindowWidth() - 1);
	}
	if (User->GetY() < 1)
	{
		User->SetSymbol('O');
		User->SetY(1);
	}
	else if (User->GetY() > Console::WindowHeight() - 2)
	{
		User->SetSymbol('O');
		User->SetY(Console::WindowHeight() - 2);
	}

	//Drawing Pacman
	Console::SetCursorPosition(User->GetX(), User->GetY());
	Console::ForegroundColor(User->GetFrontColor());
	cout << User->GetSymbol();
	Console::ForegroundColor(Gray);
	

	if (ghostMove % 2 == 1)
	{
		ghostAI();
		ghostMove = 0;
	}
	else
		ghostMove++;

	//Drawing Ghosts
	for (int i = 0; i < 4; i++)
	{
		if (Ghosts[i].GetX() == User->GetX() && Ghosts[i].GetY() == User->GetY())
			itsSimpleWeKillThePacman();
		Console::ForegroundColor(Ghosts[i].GetFrontColor());
		Console::SetCursorPosition(Ghosts[i].GetX(), Ghosts[i].GetY());
		cout << '&';
	}

	Console::ForegroundColor(Gray);
	Console::Lock(false);
	Sleep(80);

	if (!pacmanAlive)
	{
		Console::Clear();
		play = false;
		return;
	}

	//Pressing Esc
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		Console::Clear();
		play = false;
		return;
	}
}

void GamePlay::itsSimpleWeKillThePacman()
{
	User->loseLives();

	if (User->GetLives() == 0)
	{
		pacmanAlive = false;
		return;
	}

	changeSymbol = 0;
	User->resetPos();
	up = false;
	down = false;
	right = false;
	left = false;
	resetGhost();
}

void GamePlay::resetGhost()
{
	for (int i = 0; i < 4; i++)
	{
		Ghosts[i].SetX(Console::WindowWidth() / 2 - (i - 2));
		Ghosts[i].SetY(Console::WindowHeight() / 2);
	}
}

bool GamePlay::gameOver()
{
	Console::Clear();
	while (true)
	{
		Console::Lock(true);
		Console::SetCursorPosition(0, Console::WindowHeight() / 2 - 1);
		cout << "Final score: " << score;
		Console::SetCursorPosition(0, Console::WindowHeight() / 2 + 1);
		cout << "Would you like to play again? (Y)es (N)o";
		if (GetAsyncKeyState('Y'))
		{
			Console::Clear();
			return true;
		}
		else if (GetAsyncKeyState('N'))
		{
			Console::Clear();
			Console::Lock(false);
			return false;
		}
		Console::Lock(false);
		Sleep(80);
	}
}

void GamePlay::setUpWalls()
{
	ifstream pcin;

	pcin.open("PacmanLevel.pcmn");

	if (pcin.is_open())
	{
		int numberOfLinesRead = 0;
		while (true)
		{
			char readLine[32];
			pcin.getline(readLine, 32, '\n');
			/*cout << readLine;
			system("pause");*/
			
			for (int i = 0; i < 30; i++)
			{
				if (readLine[i] == '0')
					walls[i][numberOfLinesRead]->isAlive(true);
				else if (readLine[i] == 'P')
					walls[i][numberOfLinesRead]->isPowerUp(true);
				else if (readLine[i] == '.')
					walls[i][numberOfLinesRead]->isDot(true);
			}
			if (pcin.eof())
				break;
			numberOfLinesRead++;
		}
		pcin.close();
	}
	else
	{
		//file didn't open
	}

	
	//Drawing walls
	for (int x = 0; x < 30; x++)
	{
		for (int y = 0; y < 36; y++)
		{
			Console::SetCursorPosition(x, y + 1);
			if (walls[x][y]->isAlive())
			{
				Console::BackgroundColor(Blue);
				cout << ' ';
				Console::BackgroundColor(Black);
			}
			else if (walls[x][y]->isDot())
				cout << '.';
			else if (walls[x][y]->isPowerUp())
				cout << '0';
		}
	}
}
#if 1
void GamePlay::ghostAI()
{
	for (int i = 0; i < 4; i++)
	{
		if (Ghosts[i].GetAlive())
		{
			int ghostX = Ghosts[i].GetX();
			int ghostY = Ghosts[i].GetY();
			int pacX = User->GetX();
			int pacY = User->GetY();


			if (abs(ghostX - pacX) > abs(ghostY - pacY))
			{
				if (pacX > ghostX)
					Ghosts[i].SetX(ghostX += 1);
				else
					Ghosts[i].SetX(ghostX -= 1);
			}
			else if (abs(ghostX - pacX) < abs(ghostY - pacY))
			{				
				if (pacY > ghostY)
					Ghosts[i].SetY(ghostY += 1);
				else
					Ghosts[i].SetY(ghostY -= 1);
			}
			else if (ghostX == pacX && ghostY == pacY)
			{
				itsSimpleWeKillThePacman();
			}
		}
	}
}
#endif