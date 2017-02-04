#pragma once
struct Particles
{


	double m_x;
	double m_y;
	double speed;
	double direction;

public:
	Particles();
	~Particles();
	void update(int interval);
};

