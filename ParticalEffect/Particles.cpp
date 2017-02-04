#define _USE_MATH_DEFINES
#include "Particles.h"
#include <stdlib.h>
#include <math.h>


Particles::Particles():m_x(0), m_y(0)
{
	init();
}


Particles::~Particles()
{
}

void Particles::init()
{
	m_x = 0;
	m_y = 0;
	speed = (0.01 * rand()) / RAND_MAX;
	direction = (2 * M_PI * rand()) / RAND_MAX;
	speed *= speed;
}

void Particles::update(int interval)
{
	//interval to ensure speed for different machines
	direction += interval* 0.0002;

	double xspeed = speed * cos(direction);
	double yspeed = speed * sin(direction);
	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1)
	{
		init();
	}

	if (rand() < RAND_MAX / 100)
	{
		init();
	}
}