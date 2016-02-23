// EyeTribeCommDLL.h : Defines the exported functions for the DLL application.
//
#ifndef EYETRIBE_COMM_DLL_H_
#define EYETRIBE_COMM_DLL_H_

#ifndef MATLAB

#ifdef EYETRIBECOMMDLL_EXPORTS
#define EYETRIBECOMMDLL_API __declspec(dllexport)
#else
#define EYETRIBECOMMDLL_API __declspec(dllimport)
#endif

namespace EyeTribeComm
{
	class MyGaze;

	class EyeTribeComm
	{
	public:
		/*  Init() initializes the EyeTribeCommDLL.  Returns success.
		*/
		static EYETRIBECOMMDLL_API bool Init();

		static EYETRIBECOMMDLL_API bool getNewGazeData();

		static EYETRIBECOMMDLL_API void getLatestGazeData(float &a_rfX, float &a_rfY);
		static EYETRIBECOMMDLL_API void getLatestGazeQualityData(float &a_rfX, float &a_rfY, int &a_riQuality);

		static EYETRIBECOMMDLL_API void Disconnect();


		//Calibration Functions

		//Clear current Calibration
		static EYETRIBECOMMDLL_API void calibrationClear();
		//Start new Calibration Session
		static EYETRIBECOMMDLL_API bool calibrationStart(int points);
		//Start new Calibration Point
		static EYETRIBECOMMDLL_API void calibrationPointStart(int x, int y);
		//End current Calibration Point
		static EYETRIBECOMMDLL_API void calibrationPointEnd();
		//Abort Calibration Session
		static EYETRIBECOMMDLL_API void calibrationAbort();

	protected:
		/*  m_bInitialized tracks whether or not the DLL has been initialized.
		*/
		static bool m_bInitialized;

		static MyGaze m_Gaze;
	
	};
}


#endif //MATLAB
#endif //EYETRIBE_COMM_DLL_H_