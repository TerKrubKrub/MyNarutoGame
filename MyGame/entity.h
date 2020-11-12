#ifndef ENTITY
#define ENTITY

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <random>
#include <stdlib.h>
#include <functional>
#include <list>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
using namespace std;

class entity
{
public:
	sf::RectangleShape rect;
	sf::CircleShape circle;
	sf::Sprite sprite;
	sf::Text text;



private:
protected:
};

#endif