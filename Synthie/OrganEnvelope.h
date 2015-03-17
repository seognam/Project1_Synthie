#pragma once
#include "audionode.h"

class COrganEnvelope :
	public CAudioNode
{
public:
	COrganEnvelope(void);
	~COrganEnvelope(void);

public:
	virtual void Start();
	virtual bool Generate();

	void SetAttack(double a) { m_attack = a; }
	void SetRelease(double r) { m_release = r; }
	void SetDuration(double d) { m_duration = d; }
	void SetDecay(double c) { m_decay = c; }
	void SetSource(CAudioNode *node) { m_source = node; }

private:

	double  m_attack;
	double  m_release;
	double  m_duration;
	double m_decay;
	CAudioNode *m_source;
	double  m_time;
};
