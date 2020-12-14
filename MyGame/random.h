#ifndef RANDOM
#define RANDOM

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
#include <windows.h>
#include <time.h>
using namespace std;

int generateRandom(int max);
int generateRandom0(int max);
bool generateRandomBool();
int generateRandomin(int min, int max);

#endif