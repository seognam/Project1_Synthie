#include "Note.h"
#include "WavetableInstrument.h"

#pragma once
class CWavetableFactory
{
public:
	CWavetableFactory();
	virtual ~CWavetableFactory();

	void SetNote(CNote *note);

	CWavetableInstrument* CreateInstrument();

private:
	double m_amps[4];

};