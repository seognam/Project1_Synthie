#include "stdafx.h"
#include "Instrument.h"


CInstrument::CInstrument()
{
	m_gate = CGate();
	m_compress = CCompress();
	m_flange = CFlange(GetSampleRate());
	m_chorus = CChorus(GetSampleRate());
}

// Constructor to set the beats per minute
CInstrument::CInstrument(double bpm)
{
	m_bpm = bpm;

	m_gate = CGate();
	m_compress = CCompress();
	m_flange = CFlange(GetSampleRate());
	m_chorus = CChorus(GetSampleRate());
}

CInstrument::~CInstrument()
{
}

void CInstrument::SetEffectWeights(CNote* note)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);
	// Loop over the list of attributes
	for (int i = 0; i<len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);
		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);
		CComVariant value;
		attrib->get_nodeValue(&value);
		value.ChangeType(VT_R8);
		if (name == "chorusWet")
		{
			m_chorus.SetWet(value.dblVal);
		}
		else if (name == "chorusDry")
		{
			m_chorus.SetDry(value.dblVal);
		}
		else if (name == "flangeWet")
		{
			m_flange.SetWet(value.dblVal);
		}
		else if (name == "flangeDry")
		{
			m_flange.SetDry(value.dblVal);
		}
		else if (name == "compressWet")
		{
			m_compress.SetWet(value.dblVal);
		}
		else if (name == "compressDry")
		{
			m_compress.SetDry(value.dblVal);
		}
		else if (name == "gateWet")
		{
			m_gate.SetWet(value.dblVal);
		}
		else if (name == "gateDry")
		{
			m_gate.SetDry(value.dblVal);
		}
	}
}
