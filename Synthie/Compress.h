#pragma once
class CCompress
{
public:
	CCompress();
	~CCompress();

	void Process(double *frameIn);

	void SetWet(double weight) { m_wet = weight; }
	void SetDry(double weight) { m_dry = weight; }

private:
	double m_threshold;
	double m_ratio;

	double m_wet;
	double m_dry;
};
