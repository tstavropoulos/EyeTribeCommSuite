function [ bNewData ] = GetNewData
%GETNEWDATA Checks to see if there is new EyeTribe data
%   Checks to see if there is new EyeTribe data.  Returns true or false

    bNewData = (calllib('EyeTribeCommDLL','getNewGazeData') > 0);
end

