#pragma once

#include "stdafx.h"
#include "Player.h"



class GamePlay
{
	
	

public:
	GamePlay();
	~GamePlay();

	Player* User;
	Base* Enemies;

	void Play();
	void Update();
	void Render();

	bool play;
	bool up;
	bool down;
	bool right;
	bool left;
	int changeSymbol;
};