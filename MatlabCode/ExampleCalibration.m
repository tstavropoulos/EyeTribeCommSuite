function ExampleCalibration
	fprintf('Initializing EyeTribe.\n');
    EyeTribeInit();
    
    %Seconds until the task times out
    CollectionTimeout = 5; 
    
    x = zeros(1,1000);
    y = zeros(1,1000);
    
    currElem = 1;
    
    global finished;
    finished = false;
    
    figure(1);
    clf;
    ax = axes();
    h = plot(ax,0,0,'LineWidth',4);
    hold on;
    g = plot(ax,0,0,'+','LineWidth',6,'MarkerSize',30);
    hold off;
    %These are the real-pixel values that the plot occupies when maximized
    %on a 1920x1200 display
    set(ax,'xlim',[250 1738],'ylim',[158 1041]);
    %Maximize Figure
    set(gcf, 'Position', get(0,'Screensize'));
	fprintf('Beginning Data Collection.\n');
    pause(0.0001);
    
    %Prepare abort cleanup
    onCleanup(@Cleanup);
    
    
    %Perform Calibration Here
    EyeTribeCalibrationStart(8);
    DrawAndPresentPoint(g,400,400,0.25,3);
    DrawAndPresentPoint(g,1520,800,0.25,3);
    DrawAndPresentPoint(g,1000,400,0.25,3);
    DrawAndPresentPoint(g,400,800,0.25,3);
    DrawAndPresentPoint(g,1000,800,0.25,3);
    DrawAndPresentPoint(g,1000,600,0.25,3);
    DrawAndPresentPoint(g,1520,600,0.25,3);
    DrawAndPresentPoint(g,1520,400,0.25,3);
    
    tic;
    while currElem < 1000
        if ( GetNewData() )
            [x(currElem), y(currElem)] = GetGazeData();

            %Fix sign on y coordinate
            y(currElem) = translate(y(currElem));

            set(h,'xdata',x(1:currElem));
            set(h,'ydata',y(1:currElem));
            set(g,'xdata',x(currElem));
            set(g,'ydata',y(currElem));
            currElem = currElem + 1;

            %Update title with progress
            if ( mod(currElem,10) == 0 )
                title(['currElem = ',num2str(currElem),' of 1000']);
            end
            %100us pause updates plot 
            pause(0.0001);
            tic;
        elseif ( toc > CollectionTimeout )
            fprintf('Sample Collection Timeout - Took too long to acquire next sample.\n');
            break;
        end
    end
    finished = true;
    fprintf('Finished.\n');
    %Unload library
    EyeTribeCleanup();
end

function Cleanup(varargin)
%Cleanup Called if the current run gets aborted.
%   This is an attempt to guarantee the execution of the cleanup code
    global finished;
    if ( finished == false )
        fprintf('Aborted.  Cleaning Up.\n');
        EyeTribeCleanup();
    end
end

function DrawAndPresentPoint(plotobj, x, y, delay, time)
    set(plotobj,'xdata',x);
    set(plotobj,'ydata',y);
    pause(delay);
    EyeTribeCalibrationPoint(x,translate(y),time);
end

function screenCoordinate = translate(y)
    screenCoordinate = 1080 - y;
end