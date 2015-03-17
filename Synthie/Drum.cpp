#include "StdAfx.h"
#include "Drum.h"

CDrum::CDrum(void)
{
	m_duration = 0.1;
}

CDrum::~CDrum(void)
{
}


void CDrum::Start()
{
	m_wavePlayer.SetSampleRate(GetSampleRate());
	m_wavePlayer.Start();

	m_drumenvelope.SetSource(&m_wavePlayer);
	m_drumenvelope.SetSampleRate(44100);
	m_drumenvelope.Start();
}


void CDrum::SetNote(CNote *note)
{
}


bool CDrum::Generate()
{
	m_wavePlayer.Generate();
	bool valid = m_drumenvelope.Generate();

	m_frame[0] = m_drumenvelope.Frame(0);
	m_frame[1] = m_frame[0];

	return valid;
}