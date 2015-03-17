#pragma once
#include "instrument.h"
#include "Notes.h"
#include "AR.h"
#include <vector>
#include "OrganEnvelope.h"
#include "OrganWave.h"

using namespace std;

class COrganInstrument :
	public CInstrument
{
public:
	COrganInstrument(void);
	~COrganInstrument(void);
	std::wstring Name() const { return L"OrganInstrument"; }

	virtual void Start();
	virtual bool Generate();

	void SetLeslieAttackTime(double lesattack);
	void SetLeslieStartFreq(double lesstart) { m_organwave.SetLeslieStartFreq(lesstart); }
	void SetLeslieEndFreq(double lesend) { m_organwave.SetLeslieEndFreq(lesend); }
	void SetLeslieReleaseTime(double lesrelease) { m_organwave.SetLeslieReleaseTime(lesrelease); }
	void SetLeslieChanged(bool leschanged) { m_organwave.SetLeslieChanged(leschanged); }
	void SetLeslieRadius(double lesrad) { m_organwave.SetLeslieRadius(lesrad); }
	void SetLeslieFreq(double lesfreq) { m_organwave.SetLeslieFreq(lesfreq); }
	void SetFreq(double f) { m_organwave.SetFreq(f); }
	void SetAmplitude(double a) { m_organwave.SetAmplitude(a); }
	void SetDuration(double d) { m_env.SetDuration(d); m_organwave.SetDuration(d); }
	void SetDrawbars(vector<double> drawbars) { m_organwave.SetDrawbars(drawbars); }
	void SetVibratoFreq(double vfreq) { m_organwave.SetVibratoFreq(vfreq); }
	void SetVibratoMag(double vmag) { m_organwave.SetVibratoMag(vmag); }

	double GetFrame(int i) { return m_frame[i]; }
	void COrganInstrument::SetDrawbars(int drawbarNum);
	void SetNote(CNote *note);

private:
	COrganWave m_organwave;
	double m_duration;
	double m_time;
	CAR m_ar;
	COrganEnvelope m_env;
	vector<double> m_drawbars;
	bool m_leslieChanged;
};
