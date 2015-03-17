#include "StdAfx.h"
#include "WaveInstrument.h"

CWaveInstrument::CWaveInstrument(void)
{
}

CWaveInstrument::~CWaveInstrument(void)
{
}


void CWaveInstrument::Start()
{
	m_wavePlayer.SetSampleRate(GetSampleRate());
	m_wavePlayer.Start();
	m_time = 0;
	m_env.SetSource(&m_wavePlayer);
	m_env.SetSampleRate(GetSampleRate());
	m_env.Start();
	
}


void CWaveInstrument::SetNote(CNote *note)
{
	// Get a list of all attribute nodes and the
	// length of that list
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	// Loop over the list of attributes
	for (int i = 0; i < len; i++)
	{
		// Get attribute i
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		// Get the name of the attribute
		CComBSTR name;
		attrib->get_nodeName(&name);

		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "attack")
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
		/*else if (name == "pitch")
		{
			value.ChangeType(VT_R8);
			m_env.SetPitch(value.dblVal);
		}*/
	}
}


bool CWaveInstrument::Generate()
{
	/*bool valid = m_wavePlayer.Generate();

	m_frame[0] = m_wavePlayer.Frame(0);
	m_frame[1] = m_frame[0];

	return valid;*/


	m_wavePlayer.Generate();

	m_frame[0] = m_wavePlayer.Frame(0);
	m_frame[1] = m_frame[0];

	return true;

}