#ifndef MY_GAZE_H_
#define MY_GAZE_H_

#include <gazeapi.h>
#include "Logging.h"

namespace EyeTribeComm
{
	class MyGaze : public gtl::IGazeListener
	{
	public:
		MyGaze();
		~MyGaze();

		void init();

		bool getNewGazeData();
		void getLatestGazeData(float &a_rfX, float &a_rfY, int &a_riQuality);

		void disconnect();
	private:
		//IGazeListener
		void on_gaze_data(gtl::GazeData const &gaze_data);

		gtl::GazeApi m_api;

		gtl::Point2D m_p2dLastGazePoint;
		bool m_bInitialized;
		bool m_bNewGazeData;
		int m_iQuality;
	};
}


#endif // MY_GAZE_H_