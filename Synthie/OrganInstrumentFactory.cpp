#include "StdAfx.h"
#include <cmath>
#include "OrganInstrumentFactory.h"

COrganInstrumentFactory::COrganInstrumentFactory(void)
{
	m_drawbarNum = 876543210;
	m_drawbars.resize(9, 0.0);
	m_amp = 1.0;

	m_leslieAttackTime = 0.0;
	m_leslieStartFreq = 0.0;
	m_leslieReleaseTime = 0.0;
	m_leslieEndFreq = 0.0;
	m_leslieFreq = 0.0;
	m_leslieChanged = false;
	m_leslieRadius = 0.0;
}

COrganInstrumentFactory::~COrganInstrumentFactory(void)
{
}

COrganInstrument *COrganInstrumentFactory::CreateInstrument()
{
	COrganInstrument *instrument = new COrganInstrument();

	instrument->SetDrawbars(m_drawbars);
	instrument->SetAmplitude(m_amp);
	instrument->SetVibratoFreq(m_vibratoFreq);
	instrument->SetVibratoMag(m_vibratoMag);
	instrument->SetLeslieRadius(m_leslieRadius);
	instrument->SetLeslieFreq(m_leslieFreq);
	instrument->SetLeslieEndFreq(m_leslieEndFreq);
	instrument->SetLeslieStartFreq(m_leslieStartFreq);
	instrument->SetLeslieAttackTime(m_leslieAttackTime);
	instrument->SetLeslieReleaseTime(m_leslieReleaseTime);
	instrument->SetLeslieChanged(m_leslieChanged);

	return instrument;
}

void COrganInstrumentFactory::SetNote(CNote *note)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	double m_leslieOld = m_leslieFreq;
	bool m_leslieChanged = false;

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

		if (name == "drawbar")
		{
			value.ChangeType(VT_I4);
			SetDrawbars(value.intVal);
		}
		else if (name == "leslieAttackTime")
		{
			value.ChangeType(VT_R8);
			m_leslieAttackTime = value.dblVal;
		}
		else if (name == "leslieStartFreq")
		{
			value.ChangeType(VT_R8);
			m_leslieStartFreq = value.dblVal;
		}
		else if (name == "leslieReleaseTime")
		{
			value.ChangeType(VT_R8);
			m_leslieReleaseTime = value.dblVal;
		}
		else if (name == "leslieEndFreq")
		{
			value.ChangeType(VT_R8);
			m_leslieEndFreq = value.dblVal;
		}
		else if (name == "leslieFreq")
		{
			value.ChangeType(VT_R8);
			m_leslieFreq = value.dblVal;
			m_leslieChanged = true;
		}
		else if (name == "leslieRadius")
		{
			value.ChangeType(VT_R8);
			m_leslieRadius = value.dblVal;
		}

		else if (name == "vibratoFreq")
		{
			value.ChangeType(VT_R8);
			m_vibratoFreq = value.dblVal;
		}
		else if (name == "vibratoMag")
		{
			value.ChangeType(VT_R8);
			m_vibratoMag = value.dblVal;
		}
		else if (name == "amplitude")
		{
			value.ChangeType(VT_R8);
			m_amp = value.dblVal;
		}


	}

	if (m_leslieFreq == m_leslieOld)
	{
		m_leslieFreq = m_leslieEndFreq;
		m_leslieChanged = false;
	}
}

void COrganInstrumentFactory::SetDrawbars(int drawbarNum)
{
	int digit = 0;
	double sample = 0.0;


	for (int i = 0; i < 9; i++)
	{

		digit = drawbarNum % (int)pow((double)10, (9 - i));
		digit = digit / (int)pow((double)10, (8 - i));
		if (digit != 0)
		{
			m_drawbars[i] = pow(10.0, (((8 - (double)digit) * -3) / 20));
		}
	}
}
