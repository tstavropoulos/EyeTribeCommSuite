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
		//Library Functions

		//Initializes the EyeTribeCommDLL and connect to the GazeAPI
		static EYETRIBECOMMDLL_API bool Init();
		//Disconnect from the GazeAPI
		static EYETRIBECOMMDLL_API void Disconnect();


		//Gaze Data Functions

		//Test if new Gaze Data is available
		static EYETRIBECOMMDLL_API bool getNewGazeData();
		//Return most recent Gaze Data (destructive)
		static EYETRIBECOMMDLL_API void getLatestGazeData(float &a_rfX, float &a_rfY);
		//Return most recent Gaze Data with Quality information (destructive)
		static EYETRIBECOMMDLL_API void getLatestGazeQualityData(float &a_rfX, float &a_rfY, int &a_riQuality);


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
		//Get Detailed Calibration Results
		static EYETRIBECOMMDLL_API void calibrationResultsDetailed(bool &a_rbSuccess, float &a_rfDegErr, float &a_rfDegL, float &a_rfDegR);
		//Get Simple Calibration Results
		static EYETRIBECOMMDLL_API void calibrationResults(bool &a_rbSuccess);

	protected:
		//Tracks whether the Library has been initialized
		static bool m_bInitialized;

		//GazeAPI Listener
		static MyGaze m_Gaze;
	
	};
}


#endif //MATLAB
#endif //EYETRIBE_COMM_DLL_H_