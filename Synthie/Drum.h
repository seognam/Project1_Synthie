#pragma once
#include "instrument.h"
#include "WavePlayer.h"
#include "DrumEnvelope.h"
#include <vector>

class CDrum : public CInstrument
{
public:
	CDrum(void);
	virtual ~CDrum(void);

	virtual void Start();
	virtual bool Generate();
	virtual void SetNote(CNote *note);

	CWavePlayer *GetPlayer() { return &m_wavePlayer; }
	std::wstring GetName() const { return L"Drum"; }

	void GetFrame(double frame[2]){ frame[0] = m_frame[0]; frame[1] = m_frame[1]; }

private:
	CWavePlayer m_wavePlayer;
	double m_duration;
	double m_time;
	CDrumEnvelope m_drumenvelope;
};