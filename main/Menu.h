#pragma once


class Menu
{
	int choice;
	int difficultySetting;

public:
	Menu();
	~Menu();

	void mainMenu();
	void controls();
	void difficulty();
	void displayHighscores();

	//get
	int getDif();

	//Set
	void getDif(int _difficulty);
};


