#include "Swarm.h"



Swarm::Swarm():lastTime(0)
{
	m_Particles = new Particles[NPARTICLES];
}


Swarm::~Swarm()
{
	delete[] m_Particles;
}

void Swarm::update(int elapsed)
{
	int interval = elapsed - lastTime;
	for (int i = 0; i < Swarm::NPARTICLES; i++)
	{
		m_Particles[i].update(interval);
	}
	lastTime = elapsed;
}