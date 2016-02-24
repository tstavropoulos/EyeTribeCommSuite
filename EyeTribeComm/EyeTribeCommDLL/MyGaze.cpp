#include "stdafx.h"

#include "MyGaze.h"

using namespace EyeTribeComm;

MyGaze::MyGaze()
	: m_bNewGazeData(false), m_p2dLastGazePoint(), m_bInitialized(false), m_iQuality(0)
{
}

MyGaze::~MyGaze()
{
	if (m_bInitialized)
	{
		m_api.remove_listener(*this);
		m_api.disconnect();

		m_bInitialized = false;
	}
}

void MyGaze::init()
{
	//Connect to the server in push mdoe on the default TCP port (6555)
	if (!m_bInitialized && m_api.connect(true))
	{
		//Enable GazeData notifications
		m_api.add_listener(*this);
		m_bInitialized = true;
	}
}

void MyGaze::on_gaze_data(gtl::GazeData const &gaze_data)
{
	if (gaze_data.state & (gtl::GazeData::GD_STATE_TRACKING_GAZE | gtl::GazeData::GD_STATE_TRACKING_PRESENCE ))
	{
		if (gaze_data.avg.x == 0.0f && gaze_data.avg.y == 0.0f)
		{
			return;
		}

		//Mutex for update protection
		std::lock_guard<std::mutex> lock(m_mtxUpdating);
		m_p2dLastGazePoint = gaze_data.avg;
		m_bNewGazeData = true;
		m_iQuality = 1 + (gaze_data.state & gtl::GazeData::GD_STATE_TRACKING_GAZE);
	}
}


bool MyGaze::getNewGazeData()
{
	//Does not need update protection.  Only reading m_bNewGazeData and it's on the same thread as the potentially
	//	confounding method getLatestGazeData
	return m_bNewGazeData;
}

void MyGaze::getLatestGazeData(float &a_rfX, float &a_rfY, int &a_riQuality)
{
	//Mutex for update protection
	std::lock_guard<std::mutex> lock(m_mtxUpdating);
	if (!m_bNewGazeData)
	{
		//No new data available
		a_rfX = 0.0f;
		a_rfY = 0.0f;
		return;
	}

	a_rfX = m_p2dLastGazePoint.x;
	a_rfY = m_p2dLastGazePoint.y;
	a_riQuality = m_iQuality;

	//Expire stored data
	m_bNewGazeData = false;
	return;
}

void MyGaze::disconnect()
{
	if (m_bInitialized)
	{
		m_api.remove_listener(*this);
		m_api.disconnect();

		m_bInitialized = false;
	}
}

void MyGaze::calibrationClear()
{
	if (m_bInitialized)
	{
		m_api.calibration_clear();
	}
}

bool MyGaze::calibrationStart(const int points)
{
	if (m_bInitialized)
	{
		return m_api.calibration_start(points);
	}
	return false;
}

void MyGaze::calibrationPointStart(const int x, const int y)
{
	if (m_bInitialized)
	{
		m_api.calibration_point_start(x,y);
	}
}

void MyGaze::calibrationPointEnd()
{
	if (m_bInitialized)
	{
		m_api.calibration_point_end();
	}
}

void MyGaze::calibrationAbort()
{
	if (m_bInitialized)
	{
		m_api.calibration_abort();
	}
}

void MyGaze::calibrationResults(bool &a_rbSuccess, float &a_rfDegErr, float &a_rfDegL, float &a_rfDegR)
{
	if (m_bInitialized)
	{
		gtl::CalibResult calibResult;
		m_api.get_calib_result(calibResult);

		a_rbSuccess = calibResult.result;
		a_rfDegErr = calibResult.deg;
		a_rfDegL = calibResult.degl;
		a_rfDegR = calibResult.degr;
	}
}
