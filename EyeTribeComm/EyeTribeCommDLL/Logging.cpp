#include "stdafx.h"

#include "Logging.h"

#ifdef _WINDOWS
#endif

//Support adding other builds
#ifdef _WINDOWS
namespace Logging
{

	void PrintDebugTest(const std::string sMessage)
	{
		std::wstring wsMessage(sMessage.begin(), sMessage.end());

		OutputDebugString(wsMessage.c_str());
	}

	void PrintDebugTest(const std::wstring wsMessage)
	{
		OutputDebugString(wsMessage.c_str());
	}

	void PrintDebugError(const std::string sMessage)
	{
		std::wstring wsMessage(sMessage.begin(), sMessage.end());

		OutputDebugString(L"Error!");
		OutputDebugString(wsMessage.c_str());
	}

	void PrintDebugError(const std::wstring wsMessage)
	{
		OutputDebugString(L"Error!");
		OutputDebugString(wsMessage.c_str());
	}
};
#endif
