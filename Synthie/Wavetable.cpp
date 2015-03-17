#include "StdAfx.h"
#include "Wavetable.h"
#include <cmath>

CWavetable::CWavetable(void)
{
	for (int i = 0; i<4; i++)
		m_amp[i] = 1;
}

CWavetable::~CWavetable(void)
{
}


void CWavetable::Start()
{
	m_phase = 0;
}

bool CWavetable::Generate()
{
	double sample = 0;
	for (int i = 0; i<4; i++)
	{
		sample += m_amp[i] * sin(m_phase * (i * 2 + 1));
	}

	m_frame[1] = m_frame[0] = sample;
	m_phase += 2 * PI * m_freq * GetSamplePeriod();

	return true;
}