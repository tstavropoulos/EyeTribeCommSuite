function EyeTribeCalibrationStart( points )
%EyeTribeCalibrationStart Begins a calibration session
%   Begins a calibration session using the specified number of points
    
    iPoints = int32(points);
    calllib('EyeTribeCommDLL','calibrationStart', iPoints);
    
end

