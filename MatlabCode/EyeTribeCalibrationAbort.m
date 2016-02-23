function EyeTribeCalibrationAbort()
%EyeTribeCalibrationAbort Aborts the current calibration session.
    calllib('EyeTribeCommDLL','calibrationAbort');
end

