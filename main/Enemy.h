#pragma once
#include "Base.h"
class Enemy :
	public Base
{
	bool up;
	bool down;
	bool left;
	bool right;
	bool isAlive;
	bool imBlueDaBaDe;

public:
	Enemy();
	~Enemy();

	

	//Get
	bool GetAlive();
	bool getUp();
	bool getDown();
	bool getLeft();
	bool getRight();

	//Set
	void SetAlive(bool _alive);
	void setUp(bool _Up);
	void setDown(bool _Down);
	void setLeft(bool _Left);
	void setRight(bool _Right);


	//Changed things here
};