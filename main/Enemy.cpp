#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	isAlive = false;
}


Enemy::~Enemy()
{
}



//get
bool Enemy::GetAlive() { return isAlive; }

//set
void Enemy::SetAlive(bool _alive) { isAlive = _alive; }
//Changed things here
