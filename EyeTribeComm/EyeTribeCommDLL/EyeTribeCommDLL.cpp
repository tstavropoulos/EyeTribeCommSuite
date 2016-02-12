// EyeTribeCommDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#ifndef MATLAB

#include "EyeTribeCommDLL.h"
#include "Logging.h"
#include "MyGaze.h"

namespace EyeTribeComm
{
	MyGaze EyeTribeComm::m_Gaze;
	bool EyeTribeComm::m_bInitialized = false;

	bool EyeTribeComm::Init()
	{
		m_Gaze.init();

		m_bInitialized = true;

		return m_bInitialized;
	}

	bool EyeTribeComm::getNewGazeData()
	{
		return m_Gaze.getNewGazeData();
	}

	void EyeTribeComm::getLatestGazeData(float &a_rfX, float &a_rfY)
	{
		int temp;
		m_Gaze.getLatestGazeData(a_rfX, a_rfY, temp);
	}

	void EyeTribeComm::getLatestGazeQualityData(float &a_rfX, float &a_rfY, int &a_riQuality)
	{
		m_Gaze.getLatestGazeData(a_rfX, a_rfY, a_riQuality);
	}

	void EyeTribeComm::Disconnect()
	{
		m_bInitialized = false;
		m_Gaze.disconnect();
	}
}


#endif // MATLAB