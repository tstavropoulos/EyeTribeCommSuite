function EyeTribeCalibrationClear()
%EyeTribeCalibrationClear Clears the current calibration profile.
    calllib('EyeTribeCommDLL','calibrationClear');
end

