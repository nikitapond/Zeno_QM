#pragma once

#include <vector>
#include <iostream>

float RandDisturbance(float maxDist);

struct pos_vel {
	float pos, vel;
	pos_vel(float pos, float vel) : pos(pos), vel(vel) {};
	pos_vel() : pos(0), vel(0) {};
	pos_vel& operator+=(pos_vel b) {
		this->pos += b.pos;
		this->vel += b.vel;
		return *this;
	}
	pos_vel& operator/=(float b) {
		this->pos /= b;
		this->vel /= b;
		return *this;
	}

};

class Oscillator {

private:
	float mass, k, x0;
public:
	Oscillator(float mass, float k, float x0);
	std::vector<pos_vel> RunOscillator(int tSteps, float dt, int mf = -1, float distMax = 0);
	std::vector<pos_vel> RunMultipleOscillator(int tSteps, float dt, int mf = -1, float distMax = 0, int iterations=100, bool printProgress=true);

	float CalculateAverageAmplitude(int tSteps, float dt, int iterations, int mf = -1, float distMax = 0, bool printProgress =true);
};


float CalculateAverageDisturbance(std::vector<pos_vel>& pos_vel, float steadyStateFrac = 0.25);