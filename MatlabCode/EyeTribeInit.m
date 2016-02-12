%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Function:  EyeTribeInit(bRefl,bPair,bMaster)
%
%  Initializes the connection with the EyeTribe Eye Tracking device.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function EyeTribeInit()
	
	if ( ~libisloaded('EyeTribeCommDLL'))
		loadEyeTribeDLL()
	end
	calllib('EyeTribeCommDLL','Init');
end

function loadEyeTribeDLL()
	mfilepath = fileparts(which('EyeTribeInit.m'));
	addpath(fullfile(mfilepath,'..\BuiltLibs\x64\'));
	addpath(fullfile(mfilepath,'..\BuiltLibs\'));
	loadlibrary('EyeTribeCommDLL','EyeTribeCommCDLL.h');
end
