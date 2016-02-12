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
	/*  Init() initializes the EyeTribeCommDLL.  Returns success.
	*/
	EYETRIBECOMMDLL_API bool Init();

	EYETRIBECOMMDLL_API bool getNewGazeData();

	EYETRIBECOMMDLL_API void getLatestGazeData(float *a_pfX, float *a_pfY);
	EYETRIBECOMMDLL_API void getLatestGazeQualityData(float *a_pfX, float *a_pfY, int *a_piQuality);

	EYETRIBECOMMDLL_API void Disconnect();

#ifdef __cplusplus
}
#endif // __cplusplus


#endif  // NOTMATLAB
#endif  // EYETRIBE_COMM_C_DLL_H_