#pragma once
#include "instrument.h"
#include "Wavetable.h"
#include "AR.h"

class CWavetableInstrument :
	public CInstrument
{
public:
	CWavetableInstrument(void);
	~CWavetableInstrument(void);

	virtual void Start();
	virtual bool Generate();
	virtual void SetNote(CNote *note);

	void SetDuration(double d) { m_ar.SetDuration(d); }
	void SetFreq(double f) { m_sines.SetFreq(f); }


	void SetAmplitude(int i, double d) { m_sines.SetAmplitude(i, d); }

private:
	CAR         m_ar;
	double  m_time;
	double m_amps;
	CWavetable   m_sines;
};