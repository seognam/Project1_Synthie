#include "stdafx.h"
#include <vector>
#include "Flange.h"

CFlange::CFlange()
{
	m_minDelay = 0.002;
	m_maxDelay = 0.01;
	m_sampleRate = 44100;
	m_queueSize = m_maxDelay * m_sampleRate * 2 + 2;
	m_queue.resize(m_queueSize + 10);
	m_wrloc = 0;
}

CFlange::CFlange(double sampleRate)
{
	m_minDelay = 0.002;
	m_maxDelay = 0.01;
	m_sampleRate = sampleRate;
	m_queueSize = m_maxDelay * m_sampleRate * 2 + 2;
	m_queue.resize(m_queueSize + 10);
	m_wrloc = 0;
}


CFlange::~CFlange()
{
}

void CFlange::Process(double *frame, double time)
{
	m_wrloc = (int(time*m_sampleRate) * 2) % m_queueSize;
	m_queue[m_wrloc] = frame[0];
	m_queue[m_wrloc + 1] = frame[1];

	int delayed = ((m_maxDelay + m_minDelay) / 2 + sin(0.25 * 2 * 3.14159 * time) * ((m_maxDelay - m_minDelay) / 2)) * m_sampleRate;
	int rdloc = (m_wrloc + m_queueSize - delayed) % m_queueSize;

	frame[0] = frame[0] / 2 + m_queue[rdloc] / 2;
	rdloc = (rdloc + 1) % m_queueSize;
	frame[1] = frame[1] / 2 + m_queue[rdloc] / 2;
}
