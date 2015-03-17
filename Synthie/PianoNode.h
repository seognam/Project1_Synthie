#pragma once
#include "audionode.h"
#include <vector>
using namespace std;
class CPianoNode :
	public CAudioNode
{
public:
	CPianoNode(void);
	virtual ~CPianoNode(void);

	virtual void Start();
	virtual bool Generate();

	void SetDuration(double d) { m_duration = d * (60.0 / m_bpm); }
	void SetAmp(double amp) { m_amp = amp; }
	void SetSamples(vector<short> samples){ m_samples = samples; m_numsamples = samples.size(); }
	void SetPedal(bool ped) { m_pedal = ped; }
	void PedalNote(bool p) { m_pedal_noise = p; }
private:
	vector<short> m_samples;
	int    m_numsamples;
	int    m_position;
	double m_amp;
	double m_duration;
	double m_time;
	bool m_pedal;
	bool m_pedal_noise;
};


