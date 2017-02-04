#pragma once
#include "Particles.h"
class Swarm
{
private:
	Particles * m_Particles;
	int lastTime;

public:
	Swarm();
	~Swarm();
	const Particles * const getParticles() { return m_Particles; }//const pointer to a const particle
	void update(int elapsed);

	const static int NPARTICLES = 500;

};

