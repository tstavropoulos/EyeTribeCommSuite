#ifndef MY_GAZE_H_
#define MY_GAZE_H_

#include <gazeapi.h>
#include "Logging.h"

namespace EyeTribeComm
{
	//This class implements the IGazeListener in order to receive gaze updates
	class MyGaze : public gtl::IGazeListener
	{
	public:
		//Initializes local variables
		MyGaze();
		//Disconnects if still connected to the GazeAPI
		~MyGaze();

		//Connects to the GazeAPI and adds self as a listener of gaze data
		void init();

		//Queries whether new gaze data is available
		bool getNewGazeData();

		//Returns the latest gaze data, along with a value describing the quality
		void getLatestGazeData(float &a_rfX, float &a_rfY, int &a_riQuality);

		//Removes self as a listener of gaze data and disconencts from the GazeAPI
		void disconnect();

		//Clears the current server calibration
		void calibrationClear();

		//Begins a calibration with the indicated number of points
		bool calibrationStart(const int points);

		//Begins a calibration point at (x,y)
		void calibrationPointStart(const int x, const int y);

		//Ends the current calibration point
		void calibrationPointEnd();

		//Aborts the current attempt to calibrate
		void calibrationAbort();

		//Gets the current calibration results
		void calibrationResults(bool &a_rbSuccess, float &a_rfDegErr, float &a_rfDegL, float &a_rfDegR);

	private:
		//IGazeListener update function
		void on_gaze_data(gtl::GazeData const &gaze_data);

		gtl::GazeApi m_api;

		//Holds the last gaze data
		gtl::Point2D m_p2dLastGazePoint;

		//Holds whether the object is connected to the GazeAPI
		bool m_bInitialized;
		//Stores whether new gaze data is avialable
		bool m_bNewGazeData;
		//Stores the quality of the last gaze data
		int m_iQuality;

		//Update safety
		std::mutex m_mtxUpdating;
	};
}


#endif // MY_GAZE_H_