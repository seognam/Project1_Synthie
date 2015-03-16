#pragma once
class CCompress
{
public:
	CCompress();
	~CCompress();

	void Process(double *frameIn);

private:
	double m_threshold;
	double m_ratio;
};
