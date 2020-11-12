#ifndef PLAYER
#define PLAYER

#include "entity.h"

class player : public entity
{
public:
	float movementSpeed = 5;
	int attackDamage = 1;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int hp = 10;
	int coins = 0;

	player();
	void update();
	void updateMovement();

};

#endif