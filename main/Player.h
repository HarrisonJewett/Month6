#pragma once
#include "Base.h"
class Player :
	public Base
{
	bool up;
	bool down;
	bool left;
	bool right;
	int lives;

public:
	Player();
	Player(int x, int y, char _symbol, ConsoleColor front) : Base(x, y, _symbol, front) { ; }
	~Player();

	//Get
	int GetLives();

	//Set
	void loseLives();
};