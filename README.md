# EyeTribeCommSuite
A suite of C++ Libraries and MatLab scripts to pull gaze data in realtime off of an EyeTribe camera.

Setting up Libraries
=====================
Because I do not have permission to redestribute the gazeapi files, you need to set it up yourself.  The directions for doing so follow.

Copy the following header files to the /Include/ directory:
*   gazeapi.h
*   gazeapi_interfaces.h
*   gazeapi_types.h

Copy the following binary libraries built for x64 to the /BuiltLibs/x64/ directory:
*   GazeApiLib.lib
*   GazeApiLibD.lib
*   GazeApiLib.pdb

Copy the following binary libraries built for x86 to the /BuiltLibs/x86/ directory:
*   GazeApiLib.lib
*   GazeApiLibD.lib
*   GazeApiLib.pdb

Currently, the project file expects Boost files to be located as follows:
*   Boost headers located in C:\boost\include\   (As an example, for me, the complete path to chrono.hpp is C:\boost\include\boost-1_59\boost\chrono.hpp)
*   Boost libraries built for x64 are located in C:\boost\X64\lib\
*   Boost libraries built for x86 are located in C:\boost\X86\lib\

