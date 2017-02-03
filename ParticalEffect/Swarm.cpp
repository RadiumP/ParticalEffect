#include "Swarm.h"



Swarm::Swarm()
{
	m_Particles = new Particles[NPARTICLES];
}


Swarm::~Swarm()
{
	delete[] m_Particles;
}

void Swarm::update()
{
	for (int i = 0; i < Swarm::NPARTICLES; i++)
	{
		m_Particles[i].update();		
	}
}