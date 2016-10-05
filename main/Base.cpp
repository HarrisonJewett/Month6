#include "stdafx.h"
#include "Base.h"


Base::Base()
{
	xCoor = 0;
	yCoor = 0;
	isAlive = false;
	symbol = '.';
	symbolColorBack = Black;
	symbolColorFront = White;
}
Base::Base(int x, int y, bool _Alive, char _symbol, ConsoleColor back, ConsoleColor front)
{
	SetX(x);
	SetY(y);
	SetAlive(_Alive);
	SetSymbol(_symbol);
	SetBackColor(back);
	SetFrontColor(front);
}

Base::~Base()
{
}
