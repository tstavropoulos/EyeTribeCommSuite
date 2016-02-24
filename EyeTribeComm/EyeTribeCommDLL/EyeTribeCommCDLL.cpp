// EyeTribeCommCDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#ifndef NOTMATLAB

#include "EyeTribeCommCDLL.h"
#include "Logging.h"
#include "MyGaze.h"

//Tracks whether the Library has been initialized
static bool sbInitialized = false;
//GazeAPI Listener
static EyeTribeComm::MyGaze sGaze;


EYETRIBECOMMDLL_API bool Init()
{
	sGaze.init();
	sbInitialized = true;
	return sbInitialized;
}


EYETRIBECOMMDLL_API bool getNewGazeData()
{
	return sGaze.getNewGazeData();
}

EYETRIBECOMMDLL_API void getLatestGazeData(float *a_pfX, float *a_pfY)
{
	int temp;
	sGaze.getLatestGazeData(*a_pfX, *a_pfY, temp);
}

EYETRIBECOMMDLL_API void getLatestGazeQualityData(float *a_pfX, float *a_pfY, int *a_piQuality)
{
	sGaze.getLatestGazeData(*a_pfX, *a_pfY, *a_piQuality);
}

EYETRIBECOMMDLL_API void Disconnect()
{
	sbInitialized = false;
	sGaze.disconnect();
}

EYETRIBECOMMDLL_API bool calibrationStart(int points)
{
	return sGaze.calibrationStart(points);
}

EYETRIBECOMMDLL_API void calibrationPointStart(int x, int y)
{
	sGaze.calibrationPointStart(x, y);
}

EYETRIBECOMMDLL_API void calibrationPointEnd()
{
	sGaze.calibrationPointEnd();
}

EYETRIBECOMMDLL_API void calibrationAbort()
{
	sGaze.calibrationAbort();
}

EYETRIBECOMMDLL_API void calibrationClear()
{
	sGaze.calibrationClear();
}

EYETRIBECOMMDLL_API void calibrationResultsDetailed(bool *a_pbSuccess, float *a_pfDegErr, float *a_pfDegL, float *a_pfDegR)
{
	sGaze.calibrationResults(*a_pbSuccess, *a_pfDegErr, *a_pfDegL, *a_pfDegR);
}

EYETRIBECOMMDLL_API void calibrationResults(bool *a_pbSuccess)
{
	float fTemp1, fTemp2, fTemp3;
	sGaze.calibrationResults(*a_pbSuccess, fTemp1, fTemp2, fTemp3);
}

#endif // NOTMATLAB