#ifndef ENEMY
#define ENEMY

#include "entity.h"

class enemy : public entity
{
public:
	float movementSpeed = 0.1;
	float movementLength = 150;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int counter = 0;

	enemy();
	void update();
	void updateMovement();

};

#endif