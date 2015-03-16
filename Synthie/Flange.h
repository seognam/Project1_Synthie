#pragma once
#include <vector>
class CFlange
{
public:
	CFlange();
	CFlange(double sampleRate);
	~CFlange();

	void Process(double *frame, double time);

private:
	int m_queueSize;
	double m_minDelay;
	double m_maxDelay;
	double m_sampleRate;
	std::vector<double> m_queue;
	int m_wrloc;
};
