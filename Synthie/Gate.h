#pragma once
class CGate
{
public:
	CGate();
	~CGate();

	void Process(double *frameIn);

private:
	bool m_passingSound;  // For creating hysteresis loop
	double m_upperClip;
	double m_lowerClip;
};
