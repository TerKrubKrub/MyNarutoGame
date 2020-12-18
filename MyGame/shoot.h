#ifndef SHOOT
#define SHOOT

#include "entity.h"

class shoot : public entity
{
public:
	float movementSpeed = 10;
	int attackDamage = 5;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	bool destroy = false;
	int couterLifetime = 0;
	int lifeTime = 50;
	int counterAnimation = 0;
	sf::Vector2f velocity;

	shoot();
	void update();
	//void updateMovement();

};

#endif