#pragma once
#include "audionode.h"

class CDrumEnvelope :
	public CAudioNode
{
public:
	CDrumEnvelope(void);
	virtual ~CDrumEnvelope(void);


public:
	virtual void Start();
	virtual bool Generate();

	void SetAttack(double a) { m_attack = a; }
	void SetRelease(double r) { m_release = r; }
	void SetDuration(double d) { m_duration = d; }
	void SetDecay(double c) { m_decay = c; }
	void SetSustain(double s) { m_sustain = s; }
	void SetSource(CAudioNode *node) { m_source = node; }

private:

	double  m_attack;		// The attack time in seconds    
	double  m_release;		// The release time in seconds    
	double  m_duration;		// Duration of the note in seconds	
	double	m_decay;			// The decay time in seconds
	double	m_sustain;

	CAudioNode *m_source;	// Where we get the samples we will change


	double  m_time;			 // Current time when generating
};

