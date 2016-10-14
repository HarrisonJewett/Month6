#pragma once
#include "stdafx.h"


class Base
{
	int xCoor;
	int yCoor;
	char symbol;
	ConsoleColor symbolColorBack;
	System::ConsoleColor symbolColorFront;


public:
	Base();
	Base(int x, int y, char _symbol, ConsoleColor front);
	~Base();

	//Getters
	int GetX();
	int GetY();
	//bool GetAlive();
	char GetSymbol();
	ConsoleColor GetFrontColor();

	//Setters
	void SetX(int x);
	void SetY(int y);
	//void SetAlive(bool _alive);
	void SetSymbol(char _symbol);

	void SetFrontColor(ConsoleColor _front) { symbolColorFront = _front; }		
};