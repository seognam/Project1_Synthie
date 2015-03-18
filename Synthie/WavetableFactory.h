#pragma once
#include "WavetableInstrument.h"
#include "audio/DirSoundSource.h"
#include <vector>

class CWavetableFactory
{
public:
	CWavetableFactory(void);
	~CWavetableFactory(void);

	void SetNote(CNote *note);
	CWavetableInstrument *CreateInstrument();
	bool LoadFile(const char *filename);

private:
	std::vector<short> m_wave;
};