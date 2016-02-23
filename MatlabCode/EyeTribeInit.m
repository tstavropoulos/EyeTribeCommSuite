function EyeTribeInit()
%EyeTribeInit Initializes the EyeTribe tracking library.
%   Initializes the EyeTribe tracking library if it is not already loaded.
	if ( ~libisloaded('EyeTribeCommDLL'))
		LoadEyeTribeDLL64()
	end
	calllib('EyeTribeCommDLL','Init');
end

function LoadEyeTribeDLL64()
%LoadEyeTribeDLL64 Loads the x64 libraries.
	mfilepath = fileparts(which('EyeTribeInit.m'));
	addpath(fullfile(mfilepath,'..\BuiltLibs\x64\'));
	addpath(fullfile(mfilepath,'..\BuiltLibs\'));
	loadlibrary('EyeTribeCommDLL','EyeTribeCommCDLL.h');
end

function LoadEyeTribeDLL32()
%LoadEyeTribeDLL32 Loads the x86 libraries.
	mfilepath = fileparts(which('EyeTribeInit.m'));
	addpath(fullfile(mfilepath,'..\BuiltLibs\x86\'));
	addpath(fullfile(mfilepath,'..\BuiltLibs\'));
	loadlibrary('EyeTribeCommDLL','EyeTribeCommCDLL.h');
end