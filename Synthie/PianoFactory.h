#pragma once
#include "Piano.h"
#include <string>
#include <vector>
#include <map>
using namespace std;
class CPianoFactory
{
public:
	CPianoFactory(void);
	virtual ~CPianoFactory(void);
	CPiano *CreatePiano();
	void SetNote(CNote *);
	bool LoadFile(const char*);
private:
	std::vector<short> m_wave;
	bool m_pedal;
	double m_amp;
	std::map<string, std::vector<short>> m_stored_notes;
};
