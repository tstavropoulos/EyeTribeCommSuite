// EyeTribeCommCDLL.h : Defines the exported functions for the DLL application.
//
#ifndef EYETRIBE_COMM_C_DLL_H_
#define EYETRIBE_COMM_C_DLL_H_

#ifndef NOTMATLAB

#ifdef EYETRIBECOMMDLL_EXPORTS
#define EYETRIBECOMMDLL_API __declspec(dllexport)
#else
#define EYETRIBECOMMDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	//Library Functions

	//Initializes the EyeTribeCommDLL and connect to the GazeAPI
	EYETRIBECOMMDLL_API bool Init();
	//Disconnect from the GazeAPI
	EYETRIBECOMMDLL_API void Disconnect();


	//Gaze Data Functions

	//Test if new Gaze Data is available
	EYETRIBECOMMDLL_API bool getNewGazeData();
	//Return most recent Gaze Data (destructive)
	EYETRIBECOMMDLL_API void getLatestGazeData(float *a_pfX, float *a_pfY);
	//Return most recent Gaze Data with Quality information (destructive)
	EYETRIBECOMMDLL_API void getLatestGazeQualityData(float *a_pfX, float *a_pfY, int *a_piQuality);


	//Calibration Functions

	//Clear current Calibration
	EYETRIBECOMMDLL_API void calibrationClear();
	//Start new Calibration Session
	EYETRIBECOMMDLL_API bool calibrationStart(int points);
	//Start new Calibration Point
	EYETRIBECOMMDLL_API void calibrationPointStart(int x, int y);
	//End current Calibration Point
	EYETRIBECOMMDLL_API void calibrationPointEnd();
	//Abort Calibration Session
	EYETRIBECOMMDLL_API void calibrationAbort();
	//Get Detailed Calibration Results
	EYETRIBECOMMDLL_API void calibrationResultsDetailed(bool *a_pbSuccess, float *a_pfDegErr, float *a_pfDegL, float *a_pfDegR);
	//Get Simple Calibration Results
	EYETRIBECOMMDLL_API void calibrationResults(bool *a_pbSuccess);


#ifdef __cplusplus
}
#endif // __cplusplus


#endif  // NOTMATLAB
#endif  // EYETRIBE_COMM_C_DLL_H_