#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	lives = 3;
}

Player::Player(int x, int y, char _symbol, ConsoleColor front): Base(x, y, _symbol, front) 
{
	lives = 3;
}

Player::~Player()
{
}

void Player::resetPos() 
{
	Base::SetX(Console::WindowWidth() / 2);
	Base::SetY(Console::WindowHeight() / 5 * 3 + 1);
}

//Get
int Player::GetLives() { return lives; }

//Set
//Changed things here
void Player::loseLives() { lives--; }