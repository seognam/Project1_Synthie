#pragma once

#include <cmath>
class CGate
{
public:
	CGate();
	~CGate();

	void Process(double *frameIn);

	void SetWet(double weight) { m_wet = weight; }
	void SetDry(double weight) { m_dry = weight; }

private:
	bool m_passingSound;  // For creating hysteresis loop
	double m_upperClip;
	double m_lowerClip;

	double m_wet;
	double m_dry;
};
