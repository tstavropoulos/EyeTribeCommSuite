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
	if (m_api.connect(true))
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

		//gtl::Point2D const &smoothedCoordinates = gaze_data.avg;

		m_p2dLastGazePoint = gaze_data.avg;
		m_bNewGazeData = true;
		m_iQuality = 1 + (gaze_data.state & gtl::GazeData::GD_STATE_TRACKING_GAZE);
	}
}


bool MyGaze::getNewGazeData()
{
	return m_bNewGazeData;
}

void MyGaze::getLatestGazeData(float &a_rfX, float &a_rfY, int &a_riQuality)
{
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
