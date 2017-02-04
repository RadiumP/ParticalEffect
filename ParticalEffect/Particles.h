#pragma once
struct Particles
{


	
private:
	double speed;
	double direction;
	void init();

public:
	Particles();
	~Particles();
	double m_x;
	double m_y;


	void update(int interval);
	
};

