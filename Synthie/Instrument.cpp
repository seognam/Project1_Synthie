#include "stdafx.h"
#include "Instrument.h"


CInstrument::CInstrument()
{
	m_gate = CGate();
	m_compress = CCompress();
	m_flange = CFlange(GetSampleRate());
	m_chorus = CChorus(GetSampleRate());
}

// Constructor to set the beats per minute
CInstrument::CInstrument(double bpm)
{
	m_bpm = bpm;

	m_gate = CGate();
	m_compress = CCompress();
	m_flange = CFlange(GetSampleRate());
	m_chorus = CChorus(GetSampleRate());
}

CInstrument::~CInstrument()
{
}
