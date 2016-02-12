// EyeTribeCommExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../EyeTribeCommDLL/EyeTribeCommDLL.h"

using namespace std::literals;

bool bQuit = false;


BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
	case CTRL_CLOSE_EVENT:
		printf("Ctrl-Close event\n\n");
		bQuit = true;
		return TRUE;
	case CTRL_C_EVENT:
		printf("Ctrl-C event\n\n");
		bQuit = true;
		return TRUE;
	case CTRL_SHUTDOWN_EVENT:
		printf("Ctrl-Shutdown event\n\n");
		return FALSE;
	case CTRL_BREAK_EVENT:
		printf("Ctrl-Break event\n\n");
		return FALSE;
	case CTRL_LOGOFF_EVENT:
		printf("Ctrl-Logoff event\n\n");
		return FALSE;
	default:
		break;
	}
	return FALSE;
}

int main()
{
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE);
	EyeTribeComm::EyeTribeComm::Init();

	while (!bQuit)
	{
		if (EyeTribeComm::EyeTribeComm::getNewGazeData())
		{
			float x, y;
			int quality;
			EyeTribeComm::EyeTribeComm::getLatestGazeQualityData(x, y, quality);
			std::cout << "New Gaze Data: (" << x << ", " << y << ") " << "\tQuality: " << quality << std::endl;
		}

		//std::this_thread::sleep_for(100ms);
	}

	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, FALSE);
	EyeTribeComm::EyeTribeComm::Disconnect();

	std::string sInput;
	std::cin >> sInput;
	
    return 0;
}

