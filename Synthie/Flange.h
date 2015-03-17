#pragma once
#include <vector>
class CFlange
{
public:
	CFlange();
	CFlange(double sampleRate);
	~CFlange();

	void Process(double *frame, double time);

	void SetWet(double weight) { m_wet = weight; }
	void SetDry(double weight) { m_dry = weight; }

private:
	int m_queueSize;
	double m_minDelay;
	double m_maxDelay;
	double m_sampleRate;
	std::vector<double> m_queue;
	int m_wrloc;

	double m_wet;
	double m_dry;
};
