#pragma once
#include "instrument.h"
#include "WavetablePlayer.h"
#include "WavetableEnvelope.h"

class CWavetableInstrument :
	public CInstrument
{
public:
	CWavetableInstrument(void);
	~CWavetableInstrument(void);

	virtual void Start();
	virtual bool Generate();
	virtual void SetNote(CNote *note);
	virtual void SetAmplitude(double amp) { m_amplitude = amp; }
	

	CWavetablePlayer *GetPlayer() { return &m_wavetablePlayer; }

private:
	CWavetablePlayer m_wavetablePlayer;
	double m_amplitude;
	CWavetableEnvelope m_env;
};