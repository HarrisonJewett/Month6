#pragma once
#include "Base.h"
class Walls :
	public Base
{
	bool cellOn;
	bool powerUp;
	bool dot;

public:
	Walls();
	~Walls();


	//get
	bool isAlive();
	bool isPowerUp();
	bool isDot();

	//set
	void isAlive(bool _alive);
	void isPowerUp(bool _powerUp);
	void isDot(bool _dot);
};