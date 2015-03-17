#pragma once
#include "AudioNode.h"
#include "Note.h"
#include "Gate.h"
#include "Compress.h"
#include "Flange.h"
#include "Chorus.h"

class CInstrument :
	public CAudioNode
{
public:
	CInstrument();
	CInstrument(double);
	virtual ~CInstrument();
	virtual void SetNote(CNote *note) = 0;
	void SetEffectWeights(CNote *note);

	CGate   m_gate;             //!< The Noise Gating effect
	CCompress m_compress;       //!< The Compression / Limiting effect
	CFlange m_flange;           //!< The Flange effect
	CChorus m_chorus;           //!< The Chorus effect
};

