function [x, y, quality] = GetGazeData
%GetGazeData Returns the current gaze coordinates
%   Returns the X and Y screen coordinates of the current gaze, as well as
%   an integer representing the quality of that data.
	xCoord = libpointer('singlePtr',0);
    yCoord = libpointer('singlePtr',0);
    qual = libpointer('int32Ptr',0);

	%[xCoord,yCoord,qual] = calllib('EyeTribeCommDLL','getLatestGazeQualityData',xCoord,yCoord,qual);
    calllib('EyeTribeCommDLL','getLatestGazeQualityData',xCoord,yCoord,qual);
    
    x = xCoord.Value(1);
    y = yCoord.Value(1);
    quality = qual.Value(1);
end