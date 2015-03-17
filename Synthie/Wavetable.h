#pragma once
#include "audionode.h"

class CWavetable :
	public CAudioNode
{
public:
	CWavetable(void);
	~CWavetable(void);

public:
	virtual void Start();
	virtual bool Generate();

	void SetFreq(double f) { m_freq = f; }
	void SetAmplitude(int i, double a) { m_amp[i] = a; }

private:
	double m_freq;
	double m_phase;
	double m_amp[4];
};