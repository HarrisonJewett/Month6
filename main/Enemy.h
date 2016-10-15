#pragma once
#include "Base.h"
class Enemy :
	public Base
{
	//Direcetions for moving Ghosts
	bool up;
	bool down;
	bool left;
	bool right;
	//Checking if locations around ghosts are possible next locations
	bool north;
	bool south;
	bool west;
	bool east;

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

	bool getNorth();
	bool getSouth();
	bool getWest();
	bool getEast();

	//Set
	void SetAlive(bool _alive);
	void setUp(bool _Up);
	void setDown(bool _Down);
	void setLeft(bool _Left);
	void setRight(bool _Right);

	void setNorth(bool _north);
	void setSouth(bool _south);
	void setWest(bool _west);
	void setEast(bool _east);


	//Changed things here
};