#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	up = false;
	down = false;
	left = false;
	right = false;
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

//set
void Enemy::SetAlive(bool _alive) { isAlive = _alive; }
void Enemy::setUp(bool _Up) { up = _Up; }
void Enemy::setDown(bool _Down) { down = _Down; }
void Enemy::setLeft(bool _Left) { left = _Left; }
void Enemy::setRight(bool _Right) { right = _Right; }
