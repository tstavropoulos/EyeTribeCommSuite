function [x, y, quality] = GetGazeData
	xCoord = libpointer('singlePtr',0);
    yCoord = libpointer('singlePtr',0);
    qual = libpointer('int32Ptr',0);

	%[xCoord,yCoord,qual] = calllib('EyeTribeCommDLL','getLatestGazeQualityData',xCoord,yCoord,qual);
    calllib('EyeTribeCommDLL','getLatestGazeQualityData',xCoord,yCoord,qual);
    
    x = xCoord.Value(1);
    y = yCoord.Value(1);
    quality = qual.Value(1);
end