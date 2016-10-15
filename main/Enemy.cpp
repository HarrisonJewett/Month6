#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	up = false;
	down = false;
	left = false;
	right = false;
	
	north = false;
	down = false;
	west = false;
	east = false;

	isAlive = false;
}


Enemy::~Enemy()
{
}

//get
bool Enemy::GetAlive() { return isAlive; }
bool Enemy::getUp() { return up; }
bool Enemy::getDown() { return down; }
bool Enemy::getLeft() { return left; }
bool Enemy::getRight() { return right; }

bool Enemy::getNorth() { return north; }
bool Enemy::getSouth() { return south; }
bool Enemy::getWest() { return west; }
bool Enemy::getEast() { return east; }

//set
void Enemy::SetAlive(bool _alive) { isAlive = _alive; }

void Enemy::setUp(bool _Up) { up = _Up; }
void Enemy::setDown(bool _Down) { down = _Down; }
void Enemy::setLeft(bool _Left) { left = _Left; }
void Enemy::setRight(bool _Right) { right = _Right; }

void Enemy::setNorth(bool _north) { north = _north; }
void Enemy::setSouth(bool _south) { south = _south; }
void Enemy::setWest(bool _west) { west = _west; }
void Enemy::setEast(bool _east) { east = _east; }