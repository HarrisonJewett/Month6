#pragma once

class Base
{
	int xCoor;
	int yCoor;
	bool isAlive;
	char symbol;
	ConsoleColor symbolColorBack;
	ConsoleColor symbolColorFront;


public:
	Base();
	Base(int x, int y, bool _Alive, char _symbol, ConsoleColor back, ConsoleColor front);
	~Base();

	//Getters
	int GetX() { return xCoor; }
	int GetY() { return yCoor; }
	bool GetAlive() { return isAlive; }
	char GetSymbol() { return symbol; }
	ConsoleColor GetBackColor() { return symbolColorBack; }
	ConsoleColor GetFrontColor() { return symbolColorFront; }

	//Setters
	void SetX(int x) { xCoor = x; }
	void SetY(int y) { yCoor = y; }
	void SetAlive(bool _alive) { isAlive = _alive; }

	void SetSymbol(char _symbol) 
	{
		symbol = _symbol;
	}

	void SetBackColor(ConsoleColor _back) { symbolColorBack = _back; }
	void SetFrontColor(ConsoleColor _front) { symbolColorFront = _front; }

	void Update()
	{		
		//User input		
	}

	void Render()
	{
		if (isAlive)
		{
			Console::SetCursorPosition(xCoor, yCoor);
			cout << symbol;
		}
		//Showing things to the screen
	}
};