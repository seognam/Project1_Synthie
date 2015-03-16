#include "stdafx.h"
#include "Gate.h"

CGate::CGate()
{
	m_passingSound = false;
	m_upperClip = 0.01;
	m_lowerClip = 0.008;
}


CGate::~CGate()
{
}

void CGate::Process(double *frame)
{
	// Loop over the channels
	for (int c = 0; c<2; c++)
	{
		// Add output of the queue to the current input
		if ((abs(frame[c]) > m_upperClip) || (abs(frame[c]) > m_lowerClip && m_passingSound))
		{
			frame[c] = frame[c];
			m_passingSound = true;
		}
		else
		{
			frame[c] = 0;
			m_passingSound = false;
		}
	}
}
