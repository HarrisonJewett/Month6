#pragma once
#include "Base.h"
class Enemy :
	public Base
{
	bool isAlive;
	bool imBlueDaBaDe;

public:
	Enemy();
	~Enemy();

	

	//Get
	bool GetAlive();

	//Set
	void SetAlive(bool _alive);
};