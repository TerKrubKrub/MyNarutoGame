#ifndef PICKUP
#define PICKUP

#include "entity.h"

class pickup : public entity
{
public:
	bool isCol = true;
	int hp = 5;
	bool destroy = false;
	int powerupDamage = 10;
	float fireRate = 0.2;

	pickup();
	void update();

private:
};

#endif