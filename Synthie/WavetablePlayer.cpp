#include "StdAfx.h"
#include "WavetablePlayer.h"

CWavetablePlayer::CWavetablePlayer(void)
{
	m_samples = NULL;
	m_numsamples = 0;
}

CWavetablePlayer::~CWavetablePlayer(void)
{
}

void CWavetablePlayer::Start()
{
	m_position = 0;
}

bool CWavetablePlayer::Generate()
{
	if (m_position < m_numsamples)
	{
		if (m_position % 2 != 0)
		{
			m_frame[0] = m_samples[m_position] / 32768.0;
			m_frame[1] = m_frame[0];
			m_position++;
			return true;
		}
		m_position++;
		return false;
	}
	else
	{
		m_frame[1] = m_frame[0] = 0;
		return false;
	}
}