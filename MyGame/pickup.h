#ifndef PICKUP
#define PICKUP

#include "entity.h"

class pickup : public entity
{
public:
	bool isCoin = true;
	int coinValue = 5;
	bool destroy = false;


	pickup();
	void update();

private:
};

#endif