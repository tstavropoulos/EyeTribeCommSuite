function EyeTribeCalibrationPoint( x, y, t )
%EYETRIBECALIBRATIONPOINT Presents a calibration point.
%   Presents a calibration point at (x,y) for time t.
    starttime = cputime;
    
    xCoord = int32(x);
    yCoord = int32(y);
    calllib('EyeTribeCommDLL','calibrationPointStart', xCoord, yCoord);
    
    while ( cputime < starttime + t )
        %display([num2str(cputime),' < ',num2str(starttime + t)]);
    end
    
    
    calllib('EyeTribeCommDLL','calibrationPointEnd');
    
end

