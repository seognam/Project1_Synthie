#pragma once
#include "instrument.h"
#include "WavePlayer.h"
#include "WaveEnvelope.h"

class CWaveInstrument :
	public CInstrument
{
public:
	CWaveInstrument(void);
	~CWaveInstrument(void);

	virtual void Start();
	virtual bool Generate();
	virtual void SetNote(CNote *note);

	CWavePlayer *GetPlayer() { return &m_wavePlayer; }

	void SetDuration(double d) { m_env.SetDuration(d); m_wavePlayer.SetDuration(d); }

private:
	double m_duration;
	double m_time;
	CWavePlayer m_wavePlayer;
	CWaveEnvelope m_env;
};