#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	/*up = false;
	down = false;
	right = false;
	left = false;
	lives = 3;*/
}

Player::Player(int x, int y, char _symbol, ConsoleColor front): Base(x, y, _symbol, front) 
{
	up = false;
	down = false;
	right = false;
	left = false;
	lives = 3;
}

Player::~Player()
{
}

void Player::resetPos() 
{
	Base::SetX(Console::WindowWidth() / 2);
	Base::SetY(Console::WindowHeight() / 4 * 3);
}

//Get
int Player::GetLives() { return lives; }

//Set
void Player::loseLives() { lives--; }