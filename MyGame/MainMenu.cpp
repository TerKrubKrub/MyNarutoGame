#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Resources/font.otf"))
		printf("Failed");

	// START
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Red);
	mainMenu[0].setString("START");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(500, 150);

	// SCORE
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("LEADERBOARD");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(500, 300);

	// QUIT
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("QUIT");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(500, 450);

	mainMenuSelected = 0;
}

void MainMenu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; i++)
		window.draw(mainMenu[i]);
}

void MainMenu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
			mainMenuSelected = 2;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);
	}
}

void MainMenu::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
			mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);
	}
}
