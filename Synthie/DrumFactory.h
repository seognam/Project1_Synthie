#pragma once
#include "Drum.h"
#include "audio/DirSoundSource.h"
#include "DrumEnvelope.h"
#include "WavePlayer.h"
#include "AR.h"
#include <vector>

class CDrumFactory
{
public:
	CDrumFactory(void);
	virtual ~CDrumFactory(void);

	void SetNote(CNote *note);
	void SynDrum(void);

	bool CDrumFactory::LoadFile(const char *filename);

	CDrum *CreateInstrument();

	std::vector<short> Vect(int Z) { return m_table.at(Z); }


private:
	std::vector<short> m_wave;
	std::vector<short> m_vec;
	std::vector< std::vector<short> > m_table;


	CDrumEnvelope m_ar;
	CWavePlayer m_wp;
	double m_duration;
	double m_time;


};