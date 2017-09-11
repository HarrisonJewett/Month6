#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	//Displaying the menu
	menu = new Menu();
	menu->mainMenu();


	Console::Clear();

	//Adding two lines for displaying score and "Press ESC to exit"
	Console::SetWindowSize(30, 38);
	Console::SetBufferSize(30, 38);

	User = new Player(Console::WindowWidth() / 2, Console::WindowHeight() / 5 * 3 + 1, 'O', Yellow);
	Ghosts = new Enemy[4];
	srand(GetTickCount());

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
	ghostScore = 0;
	ghostMove = 0;
	pelletCount = 0;
	maxPelletCount = 0;


	int i = 0;
	for (; i < 4; ++i)
	{
		Ghosts[i].SetX(Console::WindowWidth() / 2 - (i - 1));
		Ghosts[i].SetY(Console::WindowHeight() / 2 + (i % 2));
	}

	//Turn ghost 0 on at 10 points
	//Turn ghost 1 on at 50 points
	//Turn ghost 2 on at 100 points
	//Turn ghost 3 on at 150 points

	

	setUpWalls();
}

GamePlay::~GamePlay()
{
}

void GamePlay::Play()
{
	//PlaySound(TEXT("pacmanStartup.wav"), NULL, SND_FILENAME);
	while (play)
	{
		Update();
		Render();
	}

	if (walls)
	{
		for (int x = 0; x < 30; x++)
		{
			for (int y = 0; y < 36; y++)
			{
				delete walls[x][y];
			}
			delete[] walls[x];
		}
		delete walls;
		delete User;
		delete[] Ghosts;
	}
}
void GamePlay::Update()
{
	Ghosts[0].SetFrontColor(Red);
	Ghosts[1].SetFrontColor(Cyan);
	Ghosts[2].SetFrontColor(Yellow);
	Ghosts[3].SetFrontColor(Magenta);

	if (ghostScore > 10)
		Ghosts[0].SetAlive(true);
	else if (ghostScore > 50)
		Ghosts[1].SetAlive(true);
	else if (ghostScore >= 100)
		Ghosts[2].SetAlive(true);
	else if (ghostScore >= 150)
		Ghosts[3].SetAlive(true);


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
		if (User->GetX() == 0 && User->GetY() == 19)
		{
		}
		else
		{
			if (!walls[User->GetX() - 1][User->GetY() - 1]->isAlive())
			{
				left = true;
				up = false;
				down = false;
				right = false;
			}
		}
	}
	else if (GetAsyncKeyState('D'))
	{
		if (User->GetX() == Console::WindowWidth() - 1 && User->GetY() == 19)
		{
		}
		else
		{
			if (!walls[User->GetX() + 1][User->GetY() - 1]->isAlive())
			{
				right = true;
				up = false;
				down = false;
				left = false;
			}
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
		if (walls[User->GetX()][User->GetY() - 2]->isAlive())
			up = false;
		else
		{
			if (walls[User->GetX()][User->GetY() - 2]->isDot())
			{
				score++;
				pelletCount++;
				ghostScore++;
				walls[User->GetX()][User->GetY() - 2]->isDot(false);
			}
			else if (walls[User->GetX()][User->GetY() - 2]->isPowerUp())
			{
				score += 15;
				ghostScore += 15;
				walls[User->GetX()][User->GetY() - 2]->isPowerUp(false);
			}
			if (changeSymbol % 6 > 2)
				User->SetSymbol('V');
			User->SetY(User->GetY() - 1);
		}
	}
	if (down)
	{
		if (walls[User->GetX()][User->GetY()]->isAlive())
			down = false;
		else
		{
			if (walls[User->GetX()][User->GetY()]->isDot())
			{
				score++;
				pelletCount++;
				ghostScore++;
				walls[User->GetX()][User->GetY()]->isDot(false);
			}
			else if (walls[User->GetX()][User->GetY()]->isPowerUp())
			{
				score += 15;
				ghostScore += 15;
				walls[User->GetX()][User->GetY()]->isPowerUp(false);
			}
			if (changeSymbol % 6 > 2)
				User->SetSymbol('^');
			User->SetY(User->GetY() + 1);
		}
	}
	if (left)
	{
		if (User->GetX() == 0 && User->GetY() == 19)
		{
			if (walls[Console::WindowWidth() - 1][18]->isDot())
			{
				score++;
				pelletCount++;
				ghostScore++;
				walls[Console::WindowWidth() - 1][18]->isDot(false);
			}
			User->SetX(Console::WindowWidth() - 1);
		}
		else
		{
			if (walls[User->GetX() - 1][User->GetY() - 1]->isAlive())
				left = false;

			else
			{
				if (walls[User->GetX() - 1][User->GetY() - 1]->isDot())
				{
					score++;
					pelletCount++;
					ghostScore++;
					walls[User->GetX() - 1][User->GetY() - 1]->isDot(false);
				}
				else if (walls[User->GetX() - 1][User->GetY() - 1]->isPowerUp())
				{
					score += 15;
					ghostScore += 15;
					walls[User->GetX() - 1][User->GetY() - 1]->isPowerUp(false);
				}
				if (changeSymbol % 6 > 2)
					User->SetSymbol('>');
				User->SetX(User->GetX() - 1);
			}
		}
	}
	if (right)
	{
		if (User->GetX() == Console::WindowWidth() - 1 && User->GetY() == 19)
		{
			if (walls[0][18]->isDot())
			{
				score++;
				pelletCount++;
				ghostScore++;
				walls[0][18]->isDot(false);
			}
			User->SetX(0);
		}
		else
		{
			if (walls[User->GetX() + 1][User->GetY() - 1]->isAlive())
				down = false;
			else
			{
				if (walls[User->GetX() + 1][User->GetY() - 1]->isDot())
				{
					score++;
					pelletCount++;
					ghostScore++;
					walls[User->GetX() + 1][User->GetY() - 1]->isDot(false);
				}
				else if (walls[User->GetX() + 1][User->GetY() - 1]->isPowerUp())
				{
					score += 15;
					ghostScore += 15;
					walls[User->GetX() + 1][User->GetY() - 1]->isPowerUp(false);
				}
				if (changeSymbol % 6 > 2)
					User->SetSymbol('<');
				User->SetX(User->GetX() + 1);
			}
		}
	}

	if (pelletCount == maxPelletCount)
		play = false;

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


	if (menu->getDif() == 3)
	{
		ghostAI();
	}
	else
	{
		if (ghostMove % 2 == 1)
		{
			ghostAI();
			ghostMove = 0;
		}
		else
			ghostMove++;
	}

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

	for (int i = 0; i < 4; i++)
	{
		Console::SetCursorPosition(Ghosts[i].GetX(), Ghosts[i].GetY());
		if (walls[Ghosts[i].GetX()][Ghosts[i].GetY() - 1]->isDot())
			cout << '.';
		else if (walls[Ghosts[i].GetX()][Ghosts[i].GetY() - 1]->isPowerUp())
			cout << '0';
		else
			cout << ' ';
	}

	Console::SetCursorPosition(User->GetX(), User->GetY());
	if (walls[User->GetX()][User->GetY() - 1]->isDot())
		cout << '.';
	else if (walls[User->GetX()][User->GetY() - 1]->isPowerUp())
		cout << '0';
	else
		cout << ' ';

	changeSymbol = 0;
	User->resetPos();
	up = false;
	down = false;
	right = false;
	left = false;
	ghostScore = 0;
	resetGhost();
}

void GamePlay::resetGhost()
{
	//change this
	for (int i = 0; i < 4; i++)
	{
		Ghosts[i].SetX(Console::WindowWidth() / 2 - (i - 1));
		Ghosts[i].SetY(Console::WindowHeight() / 2 + (i % 2));
		Ghosts[i].SetAlive(false);
	}
}

bool GamePlay::gameOver()
{
	ofstream binaryHighscores;

	binaryHighscores.open("Highscores.bin", ios_base::binary);
	if (binaryHighscores.is_open())
	{
		binaryHighscores.write((char*)&score, sizeof(score));

		binaryHighscores.close();
	}
	else
	{
		//file failed to load
	}

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
			Console::Lock(false);
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
	switch (menu->getDif())
	{
	case 1:
		pcin.open("EasyLevel.pcmn");
		break;
	case 2:
		pcin.open("NormalLevel.pcmn");
		break;
	case 3:
		pcin.open("Impossible.pcmn");
		break;
	default:
		break;
	}
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
				{
					walls[i][numberOfLinesRead]->isDot(true);
					maxPelletCount++;
				}
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

void GamePlay::ghostAI()
{
	vector <int> possibleDirection;

	for (int i = 0; i < 4; i++)
	{
		Ghosts[i].setNorth(false);
		Ghosts[i].setSouth(false);
		Ghosts[i].setWest(false);
		Ghosts[i].setEast(false);

		if (Ghosts[i].GetAlive())
		{
			Console::SetCursorPosition(Ghosts[i].GetX(), Ghosts[i].GetY());

			if (walls[Ghosts[i].GetX()][Ghosts[i].GetY() - 1]->isDot())
				cout << '.';
			else if (walls[Ghosts[i].GetX()][Ghosts[i].GetY() - 1]->isPowerUp())
				cout << '0';
			else
				cout << ' ';

			if (Ghosts[i].GetX() == Console::WindowWidth() - 1 && Ghosts[i].GetY() == 19)
			{
				if (Ghosts[i].getRight())
				{
					Ghosts[i].SetX(0);
				}
			}
			else if (Ghosts[i].GetX() == 0 && Ghosts[i].GetY() == 19)
			{
				if (Ghosts[i].getLeft())
				{
					Ghosts[i].SetX(Console::WindowWidth() - 1);
				}
			}
			else
			{
				if (!walls[Ghosts[i].GetX()][Ghosts[i].GetY() - 2]->isAlive())
				{
					if (!Ghosts[i].getDown())
					{
						Ghosts[i].setNorth(true);
						possibleDirection.push_back(0);
					}
				}
				if (!walls[Ghosts[i].GetX()][Ghosts[i].GetY()]->isAlive())
				{
					if (!Ghosts[i].getUp())
					{
						Ghosts[i].setSouth(1);
						possibleDirection.push_back(1);
					}
				}
				if (!walls[Ghosts[i].GetX() - 1][Ghosts[i].GetY() - 1]->isAlive())
				{
					if (!Ghosts[i].getRight())
					{
						Ghosts[i].setWest(2);
						possibleDirection.push_back(2);
					}
				}
				if (!walls[Ghosts[i].GetX() + 1][Ghosts[i].GetY() - 1]->isAlive())
				{
					if (!Ghosts[i].getLeft())
					{
						Ghosts[i].setEast(3);
						possibleDirection.push_back(3);
					}
				}
									
				/*Up = 0
				  Down = 1
				  Left = 2
				  Right = 3*/
				if (possibleDirection.size() > 0)
				{
					switch (possibleDirection[rand() % possibleDirection.size()])
					{
					case 0:
						Ghosts[i].setUp(true);
						Ghosts[i].setDown(false);
						Ghosts[i].setLeft(false);
						Ghosts[i].setRight(false);
						break;
					case 1:
						Ghosts[i].setUp(false);
						Ghosts[i].setDown(true);
						Ghosts[i].setLeft(false);
						Ghosts[i].setRight(false);
						break;
					case 2:
						Ghosts[i].setUp(false);
						Ghosts[i].setDown(false);
						Ghosts[i].setLeft(true);
						Ghosts[i].setRight(false);
						break;
					case 3:
						Ghosts[i].setUp(false);
						Ghosts[i].setDown(false);
						Ghosts[i].setLeft(false);
						Ghosts[i].setRight(true);
						break;
					default:
						break;
					}
				}
				else
				{
					if (Ghosts[i].getUp())
					{
						Ghosts[i].setDown(true);
						Ghosts[i].setUp(false);
					}
					else if (Ghosts[i].getDown())
					{
						Ghosts[i].setUp(true);
						Ghosts[i].setDown(false);						
					}
					else if (Ghosts[i].getLeft())
					{
						Ghosts[i].setRight(true);
						Ghosts[i].setLeft(false);
					}
					else if (Ghosts[i].getRight())
					{
						Ghosts[i].setLeft(true);
						Ghosts[i].setRight(false);
					}
				}

			}
			if (Ghosts[i].getUp())
			{
				Ghosts[i].SetY(Ghosts[i].GetY() - 1);
			}
			else if (Ghosts[i].getDown())
			{
				Ghosts[i].SetY(Ghosts[i].GetY() + 1);
			}
			else if (Ghosts[i].getLeft())
			{
				Ghosts[i].SetX(Ghosts[i].GetX() - 1);
			}
			else if (Ghosts[i].getRight())
			{
				Ghosts[i].SetX(Ghosts[i].GetX() + 1);
			}
			possibleDirection.clear();

		}
	}
}