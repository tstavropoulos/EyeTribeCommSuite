# EyeTribeCommSuite
A suite of C++ Libraries and MatLab scripts to pull gaze data in realtime from an EyeTribe camera.

The GazeAPI utilizes several Boost libraries.  I have provided the license files for Boost and the GazeAPI in the root directory, as well as binaries for these in the `/ThirdParty/` directory.  If the included binaries are incompatible with your compiler, you may need to compile new binaries.

Setting Up Software
====================
First, you'll need to install the EyeTribe SDK (Only available if you have ordered an EyeTribe).
The EyeTribe Server that comes with the SDK needs to be running in order to communicate with the EyeTribe.

The binary files included were built with the most recent version of Visual Studio Community 2015 (msvc140).  To use with MatLab you'll need to install that, or at least its compiler, or recompile the various libraries yourself.

To use the EyeTribeCommDLL with an application that allows you to load libraries, follow the example in the C++ application.

To use with MatLab, follow the example task `/MatlabCode/ExampleTask.m`.  Matlab first needs to be configured to work with the compiler.  Run the following command in MatLab:

    mex -setup c++
    
The output should tell you what command to execute to set up "Microsoft Visual C++ 2015 Professional". Execute the command it describes.

If you are using a 32-bit build of MatLab, go into `/MatlabCode/EyeTribeInit.m` and change `LoadEyeTribeDLL64()` to `LoadEyeTribeDLL32()`.

Using New Builds In MatLab
==========================
The libraries are set up such that every new build doesn't overwrite the existing library MatLab is loading.  If you build a new version of the EyeTribeCommDLL that you want to load into MatLab, then copy the contents of `/BuiltLibs/OutputCopy/` to `/BuiltLibs/` (ie, copy the contents up a directory).  This should overwrite the libraries that MatLab currently uses to load.

If you have a stable MatLab project, you should copy the libraries somewhere safe and modify the appropriate `/MatlabCode/EyeTribeInit.m` according.

Generating New Libraries
=========================
If you need to build new libraries, you'll need to pull a copy of the EyeTribe GazeLib (C++), and download a compatible boost distribution.

Build the appropriate version of the Boost libraries for both x64 and x86 address space (or just skip the distributions you don't care to use).

To build the x64 boost libraries, use:

    bjam msvc architecture=x86 address-model=64 stage-dir="C:/Boost/x64/" stage

To build the x86 boost libraries, use:

    bjam msvc architecture=x86 stage-dir="C:/Boost/x86/" stage

Copy the following Boost binary libraries built for x64 from `C:/Boost/x64/lib/` to the `/ThirdParty/x64/` directory:  
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

Copy the following Boost binary libraries built for x86 from `C:/Boost/x86/lib/` to the `/ThirdParty/x86/` directory:  
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

Copy the following binary libraries built for x64 to the `/ThirdParty/x64/` directory:
*   GazeApiLib.lib
*   GazeApiLibD.lib
*   GazeApiLib.pdb

Copy the following binary libraries built for x86 to the `/ThirdParty/x86/` directory:
*   GazeApiLib.lib
*   GazeApiLibD.lib
*   GazeApiLib.pdb

Copy the following GazeAPI Header files to the `/ThirdParty/Include/` directory:
*   gazeapi.h
*   gazeapi_interfaces.h
*   gazeapi_types.h

