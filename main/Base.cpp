#include "stdafx.h"
#include "Base.h"


Base::Base()
{
	xCoor = 0;
	yCoor = 0;
	symbol = '.';
	symbolColorFront = White;
}
Base::Base(int x, int y, char _symbol, ConsoleColor front)
{
	SetX(x);
	SetY(y);
	SetSymbol(_symbol);
	SetFrontColor(front);
}

Base::~Base()
{
}

//Getters
int Base::GetX() { return xCoor; }
int Base::GetY() { return yCoor; }
//bool Base::GetAlive() { return isAlive; }
char Base::GetSymbol() { return symbol; }
ConsoleColor Base::GetFrontColor() { return symbolColorFront; }

//Setters
void Base::SetX(int x) { xCoor = x; }
void Base::SetY(int y) { yCoor = y; }
//void Base::SetAlive(bool _alive) { isAlive = _alive; }
//Changed things here
void Base::SetSymbol(char _symbol) { symbol = _symbol; }