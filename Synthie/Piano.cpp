#include "StdAfx.h"
#include "Piano.h"
#include "PianoNotes.h"
CPiano::CPiano(void)
{
	m_pedal = false;
}
CPiano::~CPiano(void)
{
}
void CPiano::Start(){
	m_pianonode.SetSampleRate(GetSampleRate());
	m_pianonode.SetDuration(m_duration);
	m_pianonode.Start();
	m_time = 0;
}
bool CPiano::Generate(){
	m_pianonode.SetAmp(m_amp);
	m_pianonode.SetPedal(m_pedal);
	bool valid = m_pianonode.Generate();
	m_frame[0] = m_pianonode.Frame(0) / 32767;
	m_frame[1] = m_pianonode.Frame(1) / 32767;
	/*if(valid){
	m_time += GetSamplePeriod();
	//Reverse decay effect if the pedal is down
	if(m_pedal && m_time > 0.05){
	m_frame[0] *= ((m_duration - 0.05) / (m_duration - m_time));
	m_frame[1] *= ((m_duration - 0.05) / (m_duration - m_time));
	if(m_time > (m_duration - 0.1)){
	m_frame[0] *= ((m_duration - m_time) / 0.1);
	m_frame[1] *= ((m_duration - m_time) / 0.1);
	}
	}
	}*/
	return valid;
}
void CPiano::SetNote(CNote* note){
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
		if (name == "duration")
		{
			value.ChangeType(VT_R8);
			SetDuration(value.dblVal);
		}
		else if (name == "note"){
			//LoadFile(NoteToFile(value.bstrVal, 'l'));
			//LoadFile(NoteToFile(value.bstrVal, 's'));
			if (NoteToFile(value.bstrVal, 's') == "CompletePiano\pedald.wav"){
				m_pedal = true;
			}
			else if (NoteToFile(value.bstrVal, 's') == "CompletePiano\pedalu.wav"){
				m_pedal = false;
			}
		}
	}
}