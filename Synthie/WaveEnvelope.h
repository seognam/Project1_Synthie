#pragma once
#include "audionode.h"
class CWaveEnvelope :
	public CAudioNode
{
public:
	CWaveEnvelope(void);
	~CWaveEnvelope(void);
public:
	virtual void Start();
	virtual bool Generate();
	void SetAttack(double a) { m_attack = a; }
	void SetRelease(double r) { m_release = r; }
	void SetDuration(double d) { m_duration = d; }
	void SetDecay(double c) { m_decay = c; }
	void SetSource(CAudioNode *node) { m_source = node; }
	void SetPitch(double pitch) { m_pitch = pitch; }
private:
	double m_attack;
	double m_release;
	double m_duration;
	double m_decay;
	int m_pitch;
	CAudioNode *m_source;
	double m_time;
};