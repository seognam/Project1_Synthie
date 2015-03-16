#include "StdAfx.h"
#include "PianoNode.h"
CPianoNode::CPianoNode(void)
{
	m_numsamples = 0;
	m_amp = 1.0;
	m_time = 0.0;
}
CPianoNode::~CPianoNode(void)
{
}
void CPianoNode::Start()
{
	m_position = 0;
	m_amp = 1.0;
}
bool CPianoNode::Generate()
{
	double gain;
	if (m_time < 0.05){
		gain = m_time / 0.05;
	}
	else{
		if (!m_pedal){
			gain = (m_duration - m_time) / (m_duration - 0.05);
		}
		else{
			gain = 1.0;
		}
		if (m_time >2.0){
			gain *= 0.5;
		}
	}
	// If note reaches the end of the stored waveform, keep playing the end
	if (m_position > 352796){
		m_position = 308700;
	}
	m_frame[0] = gain*(double(m_samples[m_position++]) * m_amp + double(m_samples[m_position++]) * (1.0 - m_amp));
	m_frame[1] = gain*(double(m_samples[m_position++]) * m_amp + double(m_samples[m_position++]) * (1.0 - m_amp));
	m_time += GetSamplePeriod();
	return m_time < m_duration;
}