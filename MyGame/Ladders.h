#pragma once
#include "entity.h"

class Ladders : public entity
{
public:
	Ladders(sf::Vector2f size, sf::Vector2f position);
	//~Platform();
	void SetTexture(sf::Texture* texture);
	void SetFillColor(sf::Color color);
	void Draw(sf::RenderWindow& window);
};

