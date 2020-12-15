#pragma once
#include "entity.h"
#include "Collider.h"

class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f position);
	//~Platform();
	sf::Sprite body;

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

private:
};

