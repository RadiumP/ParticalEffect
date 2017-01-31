#include "Swarm.h"



Swarm::Swarm()
{
	m_Particles = new Particles[NPARTICLES];
}


Swarm::~Swarm()
{
	delete[] m_Particles;
}
