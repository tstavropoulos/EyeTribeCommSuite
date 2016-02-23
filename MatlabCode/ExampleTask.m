function ExampleTask
    EyeTribeInit();
    
    x = zeros(1,1000);
    y = zeros(1,1000);
    
    currElem = 1;
    
    set(gcf,'doublebuffer','on');
    set(gcf,'KeyPressFcn','keyPressed=1;');
    
    ax = axes('xlim',[-2000 2000],'ylim',[-2000 2000]);
    h = plot(ax,0,0);
    hold on;
    g = plot(ax,0,0,'o');
    hold off;
    set(ax,'xlim',[0 1920],'ylim',[0 1080]);
    while currElem < 1000
        if ( GetNewData() )
            [x(currElem),y(currElem)] = GetGazeData();
            
            %Fix sign on y coordinate
            y(currElem) = 1080 - y(currElem);
            
            set(h,'xdata',x(1:currElem));
            set(h,'ydata',y(1:currElem));
            set(g,'xdata',x(currElem));
            set(g,'ydata',y(currElem));
            currElem = currElem + 1;
            pause(0.001);
        end
    end
    
	fprintf('Quitting.\n');
    EyeTribeCleanup();
end

