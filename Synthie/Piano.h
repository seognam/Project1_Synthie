#pragma once
#include "Instrument.h"
#pragma once
#include "instrument.h"
#include "AR.h"
#include "PianoNode.h"
class CPiano :
	public CInstrument
{
public:
	CPiano(void);
	virtual ~CPiano(void);
	void SetNote(CNote*);
	void Start();
	bool Generate();

	void SetDuration(double d) { m_duration = d; }
	void SetPedal(bool state){ m_pedal = state; }
	void SetAmp(double amp){ m_amp = amp; }
	CPianoNode *GetPlayer(){ return &m_pianonode; }
private:
	double m_duration;
	double m_time;
	bool m_pedal;
	double m_amp;
	CPianoNode m_pianonode;
};

