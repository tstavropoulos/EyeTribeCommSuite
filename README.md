# EyeTribeCommSuite
A suite of C++ Libraries and MatLab scripts to pull gaze data in realtime from an EyeTribe camera.

The GazeAPI utilizes several Boost libraries.  I have provided the license files for Boost and the GazeAPI in the root directory, as well as binaries for these in the /ThirdParty/ directory.  If the included binaries are incompatible with your compiler, you may need to compile new binaries.

Setting up New Libraries
=====================
Build the appropriate version of the Boost libraries for both x64 and x86 address space (or just skip the distributions you don't care to use).

To build the x64 boost libraries, use:

    bjam msvc architecture=x86 address-model=64 stage-dir="C:/Boost/x64/" stage

To build the x86 boost libraries, use:

    bjam msvc architecture=x86 stage-dir="C:/Boost/x86/" stage

Copy the following Boost binary libraries built for x64 from C:/Boost/x64/lib/ to the /ThirdParty/x64/ directory:  
(# denote numbers, where the vc### will be dependent on your compiler version, and -#\_## will be your Boost version)
*   libboost\_chrono-vc###-mt-#\_##.lib
*   libboost\_chrono-vc###-mt-gd-#\_##.lib
*   libboost\_date\_time-vc###-mt-#\_##.lib
*   libboost\_date\_time-vc###-mt-gd-#\_##.lib
*   libboost\_regex-vc###-mt-#\_##.lib
*   libboost\_regex-vc###-mt-gd-#\_##.lib
*   libboost\_system-vc###-mt-#\_##.lib
*   libboost\_system-vc###-mt-gd-#\_##.lib
*   libboost\_thread-vc###-mt-#\_##.lib
*   libboost\_thread-vc###-mt-gd-#\_##.lib

Copy the following Boost binary libraries built for x86 from C:/Boost/x86/lib/ to the /ThirdParty/x86/ directory:  
*   libboost\_chrono-vc###-mt-#\_##.lib
*   libboost\_chrono-vc###-mt-gd-#\_##.lib
*   libboost\_date\_time-vc###-mt-#\_##.lib
*   libboost\_date\_time-vc###-mt-gd-#\_##.lib
*   libboost\_regex-vc###-mt-#\_##.lib
*   libboost\_regex-vc###-mt-gd-#\_##.lib
*   libboost\_system-vc###-mt-#\_##.lib
*   libboost\_system-vc###-mt-gd-#\_##.lib
*   libboost\_thread-vc###-mt-#\_##.lib
*   libboost\_thread-vc###-mt-gd-#\_##.lib


Link and build your GazeAPI libs as directed by the host.

Copy the following binary libraries built for x64 to the /ThirdParty/x64/ directory:
*   GazeApiLib.lib
*   GazeApiLibD.lib
*   GazeApiLib.pdb

Copy the following binary libraries built for x86 to the /ThirdParty/x86/ directory:
*   GazeApiLib.lib
*   GazeApiLibD.lib
*   GazeApiLib.pdb

Copy the following GazeAPI Header files to the /ThirdParty/Include/ directory:
*   gazeapi.h
*   gazeapi_interfaces.h
*   gazeapi_types.h

