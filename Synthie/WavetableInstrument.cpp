#include "StdAfx.h"
#include "WavetableInstrument.h"

CWavetableInstrument::CWavetableInstrument(void)
{
}

CWavetableInstrument::~CWavetableInstrument(void)
{
}


void CWavetableInstrument::Start()
{
	m_wavetablePlayer.SetSampleRate(GetSampleRate());
	m_wavetablePlayer.Start();
}


void CWavetableInstrument::SetNote(CNote *note)
{
}


bool CWavetableInstrument::Generate()
{
	bool valid = m_wavetablePlayer.Generate();

	m_frame[0] = m_wavetablePlayer.Frame(0);
	m_frame[1] = m_frame[0];

	return valid;
}