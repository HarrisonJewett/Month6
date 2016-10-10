#include "stdafx.h"
#include "Player.h"


Player::Player()
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

//Get
int Player::GetLives() { return lives; };

//Set
void Player::loseLives() { lives--; }