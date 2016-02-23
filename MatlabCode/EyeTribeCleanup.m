function EyeTribeCleanup()
%EyeTribeCleanup Ends the connection with the EyeTribe Library
%   Ends the connection with the EyeTribe Library if it is open.
	if ( libisloaded('EyeTribeCommDLL'))
        calllib('EyeTribeCommDLL','Disconnect');
	end
end