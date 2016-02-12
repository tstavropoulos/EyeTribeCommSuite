function ExampleTask
    EyeTribeInit();
    
    %Set up spacebar to end experiment
    stopkey = KbName('space');
    %Disable key output to matlab window
    ListenChar(2);
    
    while 1
        if ( GetNewData() )
            [x,y] = GetGazeData();
            display(['(',num2str(x),',',num2str(y),')']);
        end
        
        
		[keyIsDown, secs, keyCode] = KbCheck;
		if keyCode(stopkey)
			fprintf('Quit Command Received.\n');
			break;
		end
    end
    
	fprintf('Quitting.\n');
    %Reenable keyboard
	ListenChar(0);
end

