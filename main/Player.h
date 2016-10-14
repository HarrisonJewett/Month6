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
	Player(int x, int y, char _symbol, ConsoleColor front);
	~Player();

	void resetPos();

	//Get
	int GetLives();

	//Set
	void loseLives();
};