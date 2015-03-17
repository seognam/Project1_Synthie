#include "StdAfx.h"
#include "Notes.h"
#include "DrumFactory.h"
#include <cmath>

CDrumFactory::CDrumFactory(void)
{
	LoadFile("B1.wav");
	LoadFile("B2.wav");
	LoadFile("B3.wav");
	LoadFile("B4.wav");
	LoadFile("C1.wav");
	LoadFile("C2.wav");
	LoadFile("C3.wav");
	LoadFile("C4.wav");
	LoadFile("S1.wav");
	LoadFile("S2.wav");
	LoadFile("S3.wav");
	LoadFile("A1.wav");
	LoadFile("A2.wav");
	LoadFile("A3.wav");
	LoadFile("A4.wav");
	LoadFile("D1.wav");
	LoadFile("D2.wav");
	LoadFile("D3.wav");
	LoadFile("D4.wav");

	SynDrum();

}

CDrumFactory::~CDrumFactory(void)
{
}


CDrum *CDrumFactory::CreateInstrument()
{
	CDrum *instrument = new CDrum();
	instrument->GetPlayer()->SetSamples(&m_wave[0], (int)m_wave.size());

	return instrument;
}

void CDrumFactory::SetNote(CNote *note)
{
	m_ar.Start();
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);
	for (int i = 0; i<len; i++)
	{
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);
		CComBSTR name;
		attrib->get_nodeName(&name);
		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == "note")
		{
			m_wave = m_table.at(DrumToVect(value.bstrVal));
		}

		if (name == "pitch")
		{
			std::vector<short> temp;
			value.ChangeType(VT_I4);
			int t = value.intVal;
			for (unsigned i = 0; i < m_wave.size(); i++)
			{
				if (t > 3)
				{
					temp.push_back(m_wave.at(i));
					temp.push_back(m_wave.at(i));
				}
				else
				{
					if ((i % 2) == 1)
					{
						temp.push_back(m_wave.at(i));
					}
				}
			}
			m_wave = temp;
		}
		else if (name == "attack")
		{
			value.ChangeType(VT_R8);
			m_ar.SetAttack(value.dblVal);
		}
		else if (name == "decay")
		{
			value.ChangeType(VT_R8);
			m_ar.SetDecay(value.dblVal);
		}
		else if (name == "release")
		{
			value.ChangeType(VT_R8);
			m_ar.SetRelease(value.dblVal);
		}

	}


}

bool CDrumFactory::LoadFile(const char *filename)
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

	for (int i = 0; i<m_file.NumSampleFrames(); i++)
	{
		short frame[2];
		m_file.ReadFrame(frame);
		m_wave.push_back(frame[0]);
	}

	m_table.push_back(m_wave);
	m_file.Close();
	return true;
}

void CDrumFactory::SynDrum()
{
	m_wave.clear();

	m_ar.SetDuration(0.01);
	m_ar.SetAttack(0.01);
	m_ar.SetRelease(0.01);
	m_ar.SetSustain(0.1);
	m_ar.SetDecay(0.3);



	m_ar.Start();
	for (unsigned i = 0; i < .05 * 44100; i++)
	{
		short j = short(rand() % 32768);
		m_wave.push_back(j);

	}
	m_table.push_back(m_wave);


}