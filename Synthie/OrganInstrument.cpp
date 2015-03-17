#include "StdAfx.h"
#include "OrganInstrument.h"
#include <cmath>

using namespace std;

COrganInstrument::COrganInstrument(void)
{
	m_duration = 0.1;
	m_drawbars.resize(9, 0.0);
	m_leslieChanged = true;
}

COrganInstrument::~COrganInstrument(void)
{
}

void COrganInstrument::Start()
{
	m_organwave.SetSampleRate(GetSampleRate());
	m_organwave.Start();
	m_time = 0;
	m_env.SetSource(&m_organwave);
	m_env.SetSampleRate(GetSampleRate());
	m_env.Start();
}

bool COrganInstrument::Generate()
{

	m_organwave.Generate();
	bool valid = m_env.Generate();
	m_frame[0] = m_env.Frame(0);
	m_frame[1] = m_env.Frame(1);
	m_time += GetSamplePeriod();
	return valid;
}

void COrganInstrument::SetNote(CNote *note)
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

		// Get the value of the attribute.  A CComVariant is a variable
		// that can have any type. It loads the attribute value as a
		// string (UNICODE), but we can then change it to an integer 
		// (VT_I4) or double (VT_R8) using the ChangeType function 
		// and then read its integer or double value from a member variable.
		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "duration")
		{
			value.ChangeType(VT_R8);
			SetDuration(value.dblVal);
		}
		else if (name == "note")
		{
			SetFreq(NoteToFrequency(value.bstrVal));
		}
		else if (name == "leslieAttackTime")
		{
			value.ChangeType(VT_R8);
			SetLeslieAttackTime(value.dblVal);
		}
		else if (name == "leslieReleaseTime")
		{
			value.ChangeType(VT_R8);
			SetLeslieReleaseTime(value.dblVal);
		}
		else if (name == "leslieFreq")
		{
			value.ChangeType(VT_R8);
			SetLeslieFreq(value.dblVal);
			SetLeslieChanged(true);
		}
		else if (name == "leslieEndFreq")
		{
			value.ChangeType(VT_R8);
			SetLeslieEndFreq(value.dblVal);
		}
		else if (name == "leslieRadius")
		{
			value.ChangeType(VT_R8);
			SetLeslieRadius(value.dblVal);
		}
		else if (name == "vibratoMag")
		{
			value.ChangeType(VT_R8);
			SetVibratoMag(value.dblVal);
		}
		else if (name == "vibratoFreq")
		{
			value.ChangeType(VT_R8);
			SetVibratoFreq(value.dblVal);
		}
		else if (name == "attack")
		{
			value.ChangeType(VT_R8);
			m_env.SetAttack(value.dblVal);
		}
		else if (name == "decay")
		{
			value.ChangeType(VT_R8);
			m_env.SetDecay(value.dblVal);
		}
		else if (name == "release")
		{
			value.ChangeType(VT_R8);
			m_env.SetRelease(value.dblVal);
		}
		else if (name == "amplitude")
		{
			value.ChangeType(VT_R8);
			SetAmplitude(value.dblVal);
		}
		else if (name == "drawbar")
		{
			value.ChangeType(VT_I4);
			SetDrawbars(value.intVal);
		}

	}

}

void COrganInstrument::SetDrawbars(int drawbarNum)
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

	SetDrawbars(m_drawbars);
}

void COrganInstrument::SetLeslieAttackTime(double lesattack)
{
	if (m_leslieChanged)
	{
		m_organwave.SetLeslieAttackTime(lesattack);
		m_leslieChanged = false;
	}
}