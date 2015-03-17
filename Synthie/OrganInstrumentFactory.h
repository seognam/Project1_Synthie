#pragma once
#include <vector>
#include "OrganInstrument.h"

class COrganInstrumentFactory
{
public:
	COrganInstrumentFactory(void);
	~COrganInstrumentFactory(void);

	COrganInstrument *COrganInstrumentFactory::CreateInstrument();
	void COrganInstrumentFactory::SetNote(CNote *note);

	void SetDrawbars(int drawbarNum);

	double m_amp;
	double m_vibratoFreq;
	double m_vibratoMag;
	double m_leslieFreq;
	double m_leslieEndFreq;
	double m_leslieStartFreq;
	double m_leslieRadius;
	double m_leslieAttackTime;
	double m_leslieReleaseTime;
	bool m_leslieChanged;
	int m_drawbarNum;
	vector<int> m_harmonics;
	vector<double> m_drawbars;
};
