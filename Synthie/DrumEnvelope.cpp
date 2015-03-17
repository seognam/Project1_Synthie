#include "StdAfx.h"
#include "DrumEnvelope.h"

CDrumEnvelope::CDrumEnvelope(void)
{
	m_attack = 0.01;
	m_release = 0.4;
	m_duration = 1.0;
	m_sustain = 0.55;
	m_decay = 0.01;
	m_source = NULL;
}

CDrumEnvelope::~CDrumEnvelope(void)
{
}


void CDrumEnvelope::Start()
{
	m_time = 0;
}

bool CDrumEnvelope::Generate()
{
	double gain = 0.5;
	if (m_time < m_attack)
	{
		gain = (m_time / m_attack);
	}
	else if (m_time > m_attack && m_time < (m_attack + m_decay))
	{
		gain = (2 - ((m_time - m_attack) / m_decay)) / 2;
	}
	else if (m_time >= m_duration)
	{
		m_frame[0] = m_frame[1] = 0;
		return false;
	}
	else if (m_time >(m_duration - m_release))
	{
		double releaseStart = m_duration - m_release;
		gain = (1 - (m_time - releaseStart) / (m_duration - releaseStart)) / 2;
	}

	//
	// Part 2: Generate the output from the input multiplied
	// by the gain.
	//

	if (m_source != NULL)
	{
		m_frame[0] = m_source->Frame(0) * gain;
		m_frame[1] = m_source->Frame(1) * gain;
	}

	//
	// Part 3: Update the time.
	//

	m_time += GetSamplePeriod();
	return true;
}