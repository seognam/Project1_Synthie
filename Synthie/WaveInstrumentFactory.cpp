#include "StdAfx.h"
#include "WaveInstrumentFactory.h"
#include <cmath>

CWaveInstrumentFactory::CWaveInstrumentFactory(void)
{
	int my_pitch = 2;
	int my_time = 0;
	for (double time = 0; time < 2; time += 1. / 44100.)
	{
	/*my_time = time * 100000;
		if (my_time % my_pitch != 0)
		{*/
			m_wave.push_back(short(3267 * sin(2 * 3.1415 * 1000 * time)));

		//}
	}
}

CWaveInstrumentFactory::~CWaveInstrumentFactory(void)
{
}


CWaveInstrument *CWaveInstrumentFactory::CreateInstrument()
{
	CWaveInstrument *instrument = new CWaveInstrument();
	instrument->GetPlayer()->SetSamples(&m_wave[0], (int)m_wave.size());

	return instrument;
}

void CWaveInstrumentFactory::SetNote(CNote *note)
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
		
	}
	
}

bool CWaveInstrumentFactory::LoadFile(const char *filename)
{
	m_wave.clear();

	CDirSoundSource m_file;
	if (!m_file.Open(filename))
	{
		CString msg = L"Unable to open audio file: ";
		msg += filename;
		AfxMessageBox(msg);
		return false;
	}
	int my_pitch = 2;

	for (int i = 0; i<m_file.NumSampleFrames(); i++)
	{
		/*if (i % my_pitch != 0)
		{*/
			short frame[2];
			m_file.ReadFrame(frame);
			m_wave.push_back(frame[0]);
		//}
	}

	m_file.Close();
	return true;
}