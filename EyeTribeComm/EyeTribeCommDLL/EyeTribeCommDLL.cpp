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

	bool EyeTribeComm::calibrationStart(int points)
	{
		return m_Gaze.calibrationStart(points);
	}

	void EyeTribeComm::calibrationPointStart(int x, int y)
	{
		m_Gaze.calibrationPointStart(x, y);
	}

	void EyeTribeComm::calibrationPointEnd()
	{
		m_Gaze.calibrationPointEnd();
	}

	void EyeTribeComm::calibrationAbort()
	{
		m_Gaze.calibrationAbort();
	}

	void EyeTribeComm::calibrationClear()
	{
		m_Gaze.calibrationClear();
	}

	void EyeTribeComm::calibrationResultsDetailed(bool &a_rbSuccess, float &a_rfDegErr, float &a_rfDegL, float &a_rfDegR)
	{
		m_Gaze.calibrationResults(a_rbSuccess, a_rfDegErr, a_rfDegL, a_rfDegR);
	}

	void EyeTribeComm::calibrationResults(bool &a_rbSuccess)
	{
		float fTemp1, fTemp2, fTemp3;

		m_Gaze.calibrationResults(a_rbSuccess, fTemp1, fTemp2, fTemp3);
	}
}


#endif // MATLAB