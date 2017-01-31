#include "Particles.h"
#include <stdlib.h>


Particles::Particles()
{
	m_x = (2.0 * rand()) / RAND_MAX - 1;
	m_y = (2.0 * rand()) / RAND_MAX - 1;
}


Particles::~Particles()
{
}
