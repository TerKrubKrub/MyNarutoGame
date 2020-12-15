#pragma once
#include <SFML/Graphics.hpp>
#define Max_main_menu 3
class MainMenu
{
public:
	MainMenu(float width, float height, sf::View view);

	void Draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void update(sf::View view);

	int mainMenuPressed()
	{
		return mainMenuSelected;
	}
private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];
};

