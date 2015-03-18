#include "StdAfx.h"
#include "WavetableFactory.h"
#include <cmath>

CWavetableFactory::CWavetableFactory(void)
{
	for (double time = 0; time<2; time += 1. / 44100.)
	{
		m_wave.push_back(short(3267 * sin(2 * 3.1415 * 1000 * time)));
	}
}

CWavetableFactory::~CWavetableFactory(void)
{
}


CWavetableInstrument *CWavetableFactory::CreateInstrument()
{
	CWavetableInstrument *instrument = new CWavetableInstrument();
	instrument->GetPlayer()->SetSamples(&m_wave[0], (int)m_wave.size());

	return instrument;
}

void CWavetableFactory::SetNote(CNote *note)
{
}

bool CWavetableFactory::LoadFile(const char *filename)
{
	m_wave.clear();

	CDirSoundSource m_file;
	if (!m_file.Open(filename))
	{
		CString msg = L"Unable to open audio file: ";
		msg += filename;
		AfxMessageBox(msg);
		return false;
	}

	for (int i = 0; i<m_file.NumSampleFrames(); i++)
	{
		short frame[2];
		m_file.ReadFrame(frame);
		m_wave.push_back(frame[0]);
	}

	m_file.Close();
	return true;
}