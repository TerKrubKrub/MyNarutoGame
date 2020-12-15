#ifndef ENEMY2
#define ENEMY2

#include "entity.h"
#include "Collider.h"

class enemy2 : public entity
{
public:
	float movementSpeed = 1;
	float movementLength = 20;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int counter = 0;
	int hp = 30;
	bool alive = true;
	int check = 1;

	enemy2(int x, int y);
	void update(int x, int y, float dt);
	void updateMovement(int x, int y, float dt);
	void OnCollision(sf::Vector2f direction1);
	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	Collider GetCollider() { return Collider(sprite); }

private:
	sf::Vector2f velocity;
	sf::Clock clock;
};

#endif