#pragma once
#include "audionode.h"

class CWavePlayer : public CAudioNode
{
public:
	CWavePlayer(void);
	~CWavePlayer(void);

public:
	virtual void Start();
	virtual bool Generate();

	void SetSamples(short *s, int n) { m_samples = s; m_numsamples = n; }

	void SetDuration(double d) { m_duration = d * GetSampleRate(); }

private:
	short *m_samples;
	int    m_numsamples;
	int    m_position;
	double m_duration;
	int m_pitch;
};