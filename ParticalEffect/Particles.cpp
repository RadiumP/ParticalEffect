#define _USE_MATH_DEFINES
#include "Particles.h"
#include <stdlib.h>
#include <math.h>


Particles::Particles():m_x(0), m_y(0)
{
	speed = 0.001 * 2.0 * rand() / RAND_MAX;
	direction = (2 * M_PI * rand()) / RAND_MAX;
}


Particles::~Particles()
{
}

void Particles::update()
{
	double xspeed = speed * cos(direction);
	double yspeed = speed * sin(direction);
	m_x += xspeed;
	m_y += yspeed;
}