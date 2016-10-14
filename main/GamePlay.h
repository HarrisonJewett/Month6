#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Enemy.h"
#include "Walls.h"
#include "Menu.h"

class GamePlay
{
public:
	GamePlay();
	~GamePlay();

	Menu* menu;
	Player* User;
	Enemy* Ghosts;
	Walls*** walls;


	void Play();
	void Update();
	void Render();
	void setUpWalls();
	void itsSimpleWeKillThePacman();
	void resetGhost();
	void ghostAI();
	bool gameOver();
	

	bool play;
	bool up;
	bool down;
	bool right;
	bool left;
	int changeSymbol;
	bool pacmanAlive;
	int score;
	int ghostScore;
	int ghostMove;
	//Changed things here
};