#include "stdafx.h"
#include <cmath>
#include "Chorus.h"

CChorus::CChorus()
{
	m_minDelay = 0.002;
	m_maxDelay = 0.01;
	m_sampleRate = 44100;
	m_queueSize = int(m_maxDelay * m_sampleRate * 2 + 2);
	m_queue.resize(m_queueSize + 10);
	m_wrloc = 0;

	m_wet = 0;
	m_dry = 1;
}

CChorus::CChorus(double sampleRate)
{
	m_minDelay = 0.002;
	m_maxDelay = 0.01;
	m_sampleRate = sampleRate;
	m_queueSize = int(m_maxDelay * m_sampleRate * 2 + 2);
	m_queue.resize(m_queueSize + 10);
	m_wrloc = 0;

	m_wet = 0;
	m_dry = 1;
}

CChorus::~CChorus()
{
}

void CChorus::Process(double *frame, double time)
{
	m_wrloc = (int(time*m_sampleRate) * 2) % m_queueSize;
	m_queue[m_wrloc] = frame[0];
	m_queue[m_wrloc + 1] = frame[1];

	int delayed = int(((m_maxDelay + m_minDelay) / 2 + sin(0.25 * 2 * 3.14159 * time) * ((m_maxDelay - m_minDelay) / 2)) * m_sampleRate);
	int rdloc = (m_wrloc + m_queueSize - delayed) % m_queueSize;

	frame[0] = (frame[0] / 2 + m_queue[rdloc] / 2) * m_wet + frame[0] * m_dry;
	rdloc = (rdloc + 1) % m_queueSize;
	frame[1] = (frame[1] / 2 + m_queue[rdloc] / 2) * m_wet + frame[1] * m_dry;
}
