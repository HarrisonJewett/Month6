#include "stdafx.h"
#include "Walls.h"


Walls::Walls()
{
	cellOn = false;
	powerUp = false;
	dot = false;
}


Walls::~Walls()
{
}

//Get
bool Walls::isAlive() { return cellOn; }
bool Walls::isPowerUp() { return powerUp; }
bool Walls::isDot() { return dot; }

//Set
void Walls::isAlive(bool _alive) { cellOn = _alive; }
void Walls::isPowerUp(bool _powerUp) { powerUp = _powerUp; }
void Walls::isDot(bool _dot) { dot = _dot; }