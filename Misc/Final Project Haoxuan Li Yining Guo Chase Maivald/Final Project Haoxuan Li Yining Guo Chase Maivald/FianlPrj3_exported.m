classdef FianlPrj3_exported < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure               matlab.ui.Figure
        UIAxes                 matlab.ui.control.UIAxes
        UIAxes2                matlab.ui.control.UIAxes
        ExportastxtButton      matlab.ui.control.Button
        CountriesListBoxLabel  matlab.ui.control.Label
        CountriesListBox       matlab.ui.control.ListBox
        EnterCodeLabel         matlab.ui.control.Label
        EnterCodeEditField     matlab.ui.control.EditField
        TextArea               matlab.ui.control.TextArea
    end

    
    properties (Access = private)
        tempdata; % Description
        codestorage;
        codecounter;
    end
    

    methods (Access = private)

        % Value changed function: CountriesListBox
        function CountriesListBoxValueChanged(app, event)
            value = app.CountriesListBox.Value;
            switch value
                case "Syria"
                    %Humanity Data%
                    cla(app.UIAxes);
                    app.codecounter=0;
                    %Initializing first graph and all the persistent counters%
                    app.tempdata=table2array(readtable('API_SYR_DS2_en_csv_v2_10585876.csv'));
                    [row,col]=size(app.tempdata);
                    app.codestorage=strings(1,row-1);
                    col=col-1;
                    %Read dataset, turns it into an array, measure the size of the array, and initialize the user code saver%
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    tyear=zeros(1,col-5);
                    tdata=zeros(1,col-5);
                    %Initializing the temporary year saver and the data vector%
                    while(string(app.tempdata{rowpointer,4})~="SI.POV.GINI")
                        rowpointer=rowpointer+1;
                    end
                    %Finding the code for Gini Coefficient in the dataset%
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2double(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    %read and save data to tdata and tyear%
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','red');
                    app.UIAxes.XLim=[1960,2018];
                    %Drawing line and set the x axes of first graph%
                    hold(app.UIAxes);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SP.DYN.LE00.IN")
                        rowpointer=rowpointer+1;
                    end
                    %Finding the code for life expectancy in the dataset%
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                        %read and save the data into a temporary saver%
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    %Drawing line%
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="EN.POP.DNST")
                        rowpointer=rowpointer+1;
                    end
                    %Finding the code for population density in the dataset%
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                        %Saving data into temporary saver%
                    end
                    hold(app.UIAxes);
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','black');
                    %Drawing graph%
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SH.DYN.MORT")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','cyan');
                    legend(app.UIAxes,'Gini Coefficient (%) ','Life Expectancy (yrs)','Population Density (ppl per km2)','Infant Mortality Rate (ppl per 1000)');
               
                    %           %           %           %           %           %
                    %% Economic data
                    
                    rowpointer=2;
                    tempcolptr=1; 
                    cla(app.UIAxes2);
                    %Initializing the pointers and clear graph 2%
                   while(string(app.tempdata{rowpointer,4})~="NY.GDP.PCAP.KN") %% GDP per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2num(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    %read and save the data into a temporary saver%
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes2.XLim=[1960,2018];  
                    %Drawing line and set the x axes of first graph%
                    app.UIAxes2.Title.String=strcat(char(app.tempdata{2,1}), ': Economic Measures');
                    app.UIAxes2.XLabel.String = ('Years');
                    
                    hold(app.UIAxes2);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="NY.GNP.PCAP.KN") %% GNI per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    %read and save the data into a temporary saver%
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    legend(app.UIAxes2,'GDP per capita (constant LCU)','GNI per capita (constant LCU)');
                    
                    %           %           %           %           %           %
                    %% country
                    
                case "Iraq"
                    %Humanity Data%
                    app.codecounter=0;
                    cla(app.UIAxes);
                    %Initializing first graph and all the persistent counters%
                    app.tempdata=table2array(readtable('API_IRQ_DS2_en_csv_v2_10582585.csv'));
                    [row,col]=size(app.tempdata);
                    app.codestorage=strings(1,row-1);
                    col=col-1;
                    %Read dataset, turns it into an array, measure the size of the array, and initialize the user code saver%
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    tyear=zeros(1,col-5);
                    tdata=zeros(1,col-5);
                    %Initializing the temporary year saver and the data vector%
                    while(string(app.tempdata{rowpointer,4})~="SI.POV.GINI")
                        rowpointer=rowpointer+1;
                    end
                    %Finding the code for Gini Coefficient in the dataset%
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2double(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes.XLim=[min(tyear(1,:)),max(tyear(1,:))];
                    app.UIAxes.XLabel.String = ('Years');
                    
                    hold(app.UIAxes);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SP.DYN.LE00.IN")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="EN.POP.DNST")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    hold(app.UIAxes);
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','black');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SH.DYN.MORT")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','cyan');
                    app.UIAxes.Title.String=strcat(char(app.tempdata{2,1}),' Conflict: March 2003-December 2011');
                     legend(app.UIAxes,'Gini Coefficient (%) ','Life Expectancy (yrs)','Population Density (ppl per km2)','Infant Mortality Rate (ppl per 1000)');
                    
                    %           %           %           %           %           %
                    %% Economic data
                    
                    rowpointer=2;
                    tempcolptr=1; 
                    cla(app.UIAxes2);
                    %Initializing the pointers and clear graph 2%
                   while(string(app.tempdata{rowpointer,4})~="NY.GDP.PCAP.KN") %% GDP per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2num(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes2.XLim=[1960,2018];
                    app.UIAxes2.Title.String=strcat(char(app.tempdata{2,1}), ': Economic Measures');
                    app.UIAxes2.XLabel.String = ('Years');
                    
                    hold(app.UIAxes2);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="NY.GNP.PCAP.KN") %% GNI per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    legend(app.UIAxes2,'GDP per capita (constant LCU)','GNI per capita (constant LCU)');
                    
                    %           %           %           %           %           %
                    %% country
                    
                case "Afghanistan"
                    %Humanity Data%
                    app.codecounter=0;
                    cla(app.UIAxes);
                    %Initializing first graph and all the persistent counters%
                    app.tempdata=table2array(readtable('API_AFG_DS2_en_csv_v2_10580055.csv'));
                    [row,col]=size(app.tempdata);
                    app.codestorage=strings(1,row-1);
                    col=col-1;
                    %Read dataset, turns it into an array, measure the size of the array, and initialize the user code saver%
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    tyear=zeros(1,col-5);
                    tdata=zeros(1,col-5);
                    %Initializing the temporary year saver and the data vector%
                    while(string(app.tempdata{rowpointer,4})~="SI.POV.GINI")
                        rowpointer=rowpointer+1;
                    end
                    %Finding the code for Gini Coefficient in the dataset%
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2double(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes.XLim=[min(tyear(1,:)),max(tyear(1,:))];
                    app.UIAxes.XLabel.String = ('Years');
                    
                    hold(app.UIAxes);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SP.DYN.LE00.IN")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="EN.POP.DNST")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    hold(app.UIAxes);
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','black');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SH.DYN.MORT")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','cyan');
                    app.UIAxes.Title.String=strcat(char(app.tempdata{2,1}),' Conflict: October 2001-Present');
                    legend(app.UIAxes,'Gini Coefficient (%) ','Life Expectancy (yrs)','Population Density (ppl per km2)','Infant Mortality Rate (ppl per 1000)');
                    
                    %           %           %           %           %           %
                    %% Economic data
                    
                    rowpointer=2;
                    tempcolptr=1; 
                    cla(app.UIAxes2);
                    %Initializing the pointers and clear graph 2%
                   while(string(app.tempdata{rowpointer,4})~="NY.GDP.PCAP.KN") %% GDP per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2num(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes2.XLim=[1960,2018];
                    app.UIAxes2.Title.String=strcat(char(app.tempdata{2,1}), ': Economic Measures');
                    app.UIAxes2.XLabel.String = ('Years');
                    
                    hold(app.UIAxes2);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="NY.GNP.PCAP.KN") %% GNI per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    legend(app.UIAxes2,'GDP per capita (constant LCU)','GNI per capita (constant LCU)');
                   
                    %           %           %           %           %           %
                    %% country
                    
                case "Ukraine"
                    %Humanity Data%
                    app.codecounter=0;
                    cla(app.UIAxes);
                    %Initializing first graph and all the persistent counters%
                    app.tempdata=table2array(readtable('API_UKR_DS2_en_csv_v2_10587202.csv'));
                    [row,col]=size(app.tempdata);
                    app.codestorage=strings(1,row-1);
                    col=col-1;
                    %Read dataset, turns it into an array, measure the size of the array, and initialize the user code saver%
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    tyear=zeros(1,col-5);
                    tdata=zeros(1,col-5);
                    %Initializing the temporary year saver and the data vector%
                    while(string(app.tempdata{rowpointer,4})~="SI.POV.GINI")
                        rowpointer=rowpointer+1;
                    end
                    %Finding the code for Gini Coefficient in the dataset%
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2double(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes.XLim=[min(tyear(1,:)),max(tyear(1,:))];
                    app.UIAxes.XLabel.String = ('Years');
                    
                    hold(app.UIAxes);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SP.DYN.LE00.IN")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="EN.POP.DNST")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    app.UIAxes.Title.String=strcat(char(app.tempdata{2,1}),' Conflict: February 2014-Present');
                    hold(app.UIAxes);
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','black');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SH.DYN.MORT")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','cyan');
                    
                    %           %           %           %           %           %
                    %% economic data
                    
                    rowpointer=2;
                    tempcolptr=1; 
                    cla(app.UIAxes2);
                    %Initializing the pointers and clear graph 2%
                   while(string(app.tempdata{rowpointer,4})~="NY.GDP.PCAP.KN") %% GDP per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2num(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes2.XLim=[1960,2018];
                    app.UIAxes2.Title.String=strcat(char(app.tempdata{2,1}), ': Economic Measures');
                    app.UIAxes2.XLabel.String = ('Years');
                    
                    hold(app.UIAxes2);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="NY.GNP.PCAP.KN") %% GNI per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    legend(app.UIAxes2,'GDP per capita (constant LCU)','GNI per capita (constant LCU)');
                    
                    legend(app.UIAxes,'Gini Coefficient (%) ','Life Expectancy (yrs)','Population Density (ppl per km2)','Infant Mortality Rate (ppl per 1000)');
              
                    %           %           %           %           %           %
                    %% country
                    
                case "Yemen"
                    %Humanity Data%
                    app.codecounter=0;
                    cla(app.UIAxes);
                    %Initializing first graph and all the persistent counters%
                    app.tempdata=table2array(readtable('API_YEM_DS2_en_csv_v2_10587519.csv'));
                    [row,col]=size(app.tempdata);
                    app.codestorage=strings(1,row-1);
                    col=col-1;
                    %Read dataset, turns it into an array, measure the size of the array, and initialize the user code saver%
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    tyear=zeros(1,col-5);
                    tdata=zeros(1,col-5);
                    %Initializing the temporary year saver and the data vector%
                    while(string(app.tempdata{rowpointer,4})~="SI.POV.GINI")
                        rowpointer=rowpointer+1;
                    end
                    %Finding the code for Gini Coefficient in the dataset%
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2double(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes.XLim=[min(tyear(1,:)),max(tyear(1,:))];
                    app.UIAxes.XLabel.String = ('Years');
                    
                    hold(app.UIAxes);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SP.DYN.LE00.IN")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="EN.POP.DNST")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    app.UIAxes.Title.String = strcat(char(app.tempdata{2,1}),' Conflict: March 2015-Present');
                    hold(app.UIAxes);
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','black');
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="SH.DYN.MORT")
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','cyan');
                    legend(app.UIAxes,'Gini Coefficient (%) ','Life Expectancy (yrs)','Population Density (ppl per km2)','Infant Mortality Rate (ppl per 1000)');
                    
                    %           %           %           %           %           %
                    %% economic data
                    
                    rowpointer=2;
                    tempcolptr=1; 
                    cla(app.UIAxes2);
                    %Initializing the pointers and clear graph 2%
                   while(string(app.tempdata{rowpointer,4})~="NY.GDP.PCAP.KN") %% GDP per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{1,datacolptr})
                            tyear(1,tempcolptr)=0;
                        else
                            tyear(1,tempcolptr)=str2num(app.tempdata{1,datacolptr});
                        end
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','green');
                    app.UIAxes2.XLim=[1960,2018];
                    app.UIAxes2.Title.String= ('Yemen: Economic Measures');
                    app.UIAxes2.XLabel.String = ('Years');
                    
                    hold(app.UIAxes2);
                    rowpointer=2;
                    tempcolptr=1;
                    %Initializing the pointers%
                    while(string(app.tempdata{rowpointer,4})~="NY.GNP.PCAP.KN") %% GNI per capita (constant LCU)
                        rowpointer=rowpointer+1;
                    end
                    for datacolptr=5:col
                        if isempty(app.tempdata{rowpointer,datacolptr})
                            tdata(1,tempcolptr)=0;
                        else
                            tdata(1,tempcolptr)=str2num(app.tempdata{rowpointer,datacolptr});
                        end
                        tempcolptr=tempcolptr+1;
                    end
                    line(app.UIAxes2,tyear(1,:),tdata(1,:),'Linewidth',2,'Color','blue');
                    legend(app.UIAxes2,'GDP per capita (constant LCU)','GNI per capita (constant LCU)');
                    
            end
        end

        % Button pushed function: ExportastxtButton
        function ExportastxtButtonPushed(app, event)
            fid1=fopen('SavedData.txt','w');
            fprintf(fid1,'Country Name: ');
            %Create a file with a head "Country Name"%
            [row,col]=size(app.tempdata);
            col=col-1;
            rowpointer=2;
            %Measure the size of dataset that graph 1 is using%
            fprintf(fid1,'%s\n',app.tempdata{2,1});
            %Write Country name into txt file%
            for datacolptr=5:col
            fprintf(fid1,'%d ',str2double(app.tempdata{1,datacolptr}));
            end
            %Write years into file, separated with space%
            fprintf(fid1,'\n');
            while(string(app.tempdata{rowpointer,4})~="SI.POV.GINI")
                rowpointer=rowpointer+1;
            end
            %Finding the code for Gini Coefficient in the dataset%
            fprintf(fid1,'%s\n',app.tempdata{rowpointer,3});
            for datacolptr=5:col
                if isempty(app.tempdata{rowpointer,datacolptr})
                    fprintf(fid1,'0 ');
                else
                    fprintf(fid1,'%s ',app.tempdata{rowpointer,datacolptr});
                end
            end
            %Write the data into txt file, separated by space%
            fprintf(fid1,'\n');
            rowpointer=2;
            %Initialize the rowpointer%
            while(string(app.tempdata{rowpointer,4})~="SP.DYN.LE00.IN")
                rowpointer=rowpointer+1;
            end
            %Finding the code for life expectancy in the dataset%
            fprintf(fid1,'%s\n',app.tempdata{rowpointer,3});
            for datacolptr=5:col
                if isempty(app.tempdata{rowpointer,datacolptr})
                    fprintf(fid1,'0 ');
                else
                    fprintf(fid1,'%s ',app.tempdata{rowpointer,datacolptr});
                end
            end
            %Write the data into txt file, separated by space%
            fprintf(fid1,'\n');
            rowpointer=2;
            %Initialize the pointer%
            while(string(app.tempdata{rowpointer,4})~="EN.POP.DNST")
                rowpointer=rowpointer+1;
            end
            %Finding the code for population density%
            fprintf(fid1,'%s\n',app.tempdata{rowpointer,3});
            for datacolptr=5:col
                if isempty(app.tempdata{rowpointer,datacolptr})
                    fprintf(fid1,'0 ');
                else
                    fprintf(fid1,'%s ',app.tempdata{rowpointer,datacolptr});
                end
            end
            %Save the data into txt file, separated by space%
            fprintf(fid1,'\n');
            rowpointer=2;
            %Initializing pointer%
            while(string(app.tempdata{rowpointer,4})~="SH.DYN.MORT")
                rowpointer=rowpointer+1;
            end
            %Finding code for infant mortality%
            fprintf(fid1,'%s\n',app.tempdata{rowpointer,3});
            for datacolptr=5:col
                if isempty(app.tempdata{rowpointer,datacolptr})
                    fprintf(fid1,'0 ');
                else
                    fprintf(fid1,'%s ',app.tempdata{rowpointer,datacolptr});
                end
            end
            %Write the data into txt file, separated by space%
            codestoragecounter=1;
            %Reset the code storage counter%
            while(isempty(char(app.codestorage(1,codestoragecounter)))==0)
                fprintf(fid1,'\n');
                rowpointer=2;
                %checking if the user has typed any code into the app and reset the row pointer%
                while(string(app.tempdata{rowpointer,4})~=app.codestorage(1,codestoragecounter))
                    rowpointer=rowpointer+1;
                    if rowpointer==row+1
                        break
                        %Check if the codestorage is empty. If it is, break from the while loop and close the file. If it's note, find the code in the dataset%
                    end
                end
                fprintf(fid1,'%s\n',app.tempdata{rowpointer,3});
                %Write the description of the index presenting in the file%
                for datacolptr=5:col
                    if isempty(app.tempdata{rowpointer,datacolptr})
                        fprintf(fid1,'0 ');
                    else
                        fprintf(fid1,'%s ',app.tempdata{rowpointer,datacolptr});
                    end
                end
                %Saving the index into file, using space to separate them%
                codestoragecounter=codestoragecounter+1;
                %Move the code pointer one block next and prepare to check the next code saved in the codestorage%
            end
            fclose('all');
        end

        % Value changed function: EnterCodeEditField
        function EnterCodeEditFieldValueChanged(app, event)
            value = app.EnterCodeEditField.Value;
            [row,col]=size(app.tempdata);
            %Measuring the size of dataset%
            if isempty(app.codecounter)||(app.codecounter==0)
                app.codecounter=1;
            end
            %Record the number of codes the users have typed in%
            codestoragecounter=app.codecounter;
            col=col-1;
            rowpointer=2;
            tempcolptr=1;
            %Initializing pointers%
            tyear=zeros(1,col-5);
            tdata=zeros(1,col-5);
            %Initializing the temporary year saver and the data vector%
            while(string(app.tempdata{rowpointer,4})~=value)
                rowpointer=rowpointer+1;
                if rowpointer==row+1;
                    rowpointer=0;
                    break
                end
            end
            %Comparing the code that user has typed in with the existing code in the dataset%
            if row~=0
            for datacolptr=5:col
                if isempty(app.tempdata{1,datacolptr})
                    tyear(1,tempcolptr)=0;
                else
                    tyear(1,tempcolptr)=str2double(app.tempdata{1,datacolptr});
                end
                if isempty(app.tempdata{rowpointer,datacolptr})
                    tdata(1,tempcolptr)=0;
                else
                    tdata(1,tempcolptr)=str2double(app.tempdata{rowpointer,datacolptr});
                end
                tempcolptr=tempcolptr+1;
            end
            %If the code does not exist, do not plot anything. If it exist, plot graphs based on the recorded data%
            hold(app.UIAxes,'on'); 
            line(app.UIAxes,tyear(1,:),tdata(1,:));
            oldlegdata=string(app.UIAxes.Legend.String);
            %Read the previous legend%
            oldlegdata(1,length(oldlegdata))=string(app.tempdata{rowpointer,3});
            %Put the description of the new data into the legend string array%
            legend(app.UIAxes,oldlegdata);
            %Presenting new legend%
            app.codestorage(1,codestoragecounter)=string(value);
            %Save the valid code into codestorage%
            app.codecounter=app.codecounter+1;
            end
        end

        % Callback function
        function ColorBlindFriendlyButtonGroupSelectionChanged(app, event)
            selectedButton = app.ColorBlindFriendlyButtonGroup.SelectedObject;
                   
        end
    end

    % App initialization and construction
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure
            app.UIFigure = uifigure;
            app.UIFigure.Position = [100 100 825 651];
            app.UIFigure.Name = 'UI Figure';

            % Create UIAxes
            app.UIAxes = uiaxes(app.UIFigure);
            title(app.UIAxes, 'Title')
            xlabel(app.UIAxes, 'X')
            ylabel(app.UIAxes, 'Y')
            app.UIAxes.PlotBoxAspectRatio = [1 0.358916478555305 0.358916478555305];
            app.UIAxes.Position = [161 347 662 286];

            % Create UIAxes2
            app.UIAxes2 = uiaxes(app.UIFigure);
            title(app.UIAxes2, 'Title')
            xlabel(app.UIAxes2, 'X')
            ylabel(app.UIAxes2, 'Y')
            app.UIAxes2.PlotBoxAspectRatio = [1 0.291196388261851 0.291196388261851];
            app.UIAxes2.Position = [161 23 664 301];

            % Create ExportastxtButton
            app.ExportastxtButton = uibutton(app.UIFigure, 'push');
            app.ExportastxtButton.ButtonPushedFcn = createCallbackFcn(app, @ExportastxtButtonPushed, true);
            app.ExportastxtButton.Position = [12 373 100 22];
            app.ExportastxtButton.Text = 'Export as .txt';

            % Create CountriesListBoxLabel
            app.CountriesListBoxLabel = uilabel(app.UIFigure);
            app.CountriesListBoxLabel.HorizontalAlignment = 'right';
            app.CountriesListBoxLabel.Position = [43 630 57 22];
            app.CountriesListBoxLabel.Text = 'Countries';

            % Create CountriesListBox
            app.CountriesListBox = uilistbox(app.UIFigure);
            app.CountriesListBox.Items = {'Syria', 'Iraq', 'Afghanistan', 'Ukraine', 'Yemen'};
            app.CountriesListBox.ValueChangedFcn = createCallbackFcn(app, @CountriesListBoxValueChanged, true);
            app.CountriesListBox.Position = [1 455 150 178];
            app.CountriesListBox.Value = 'Syria';

            % Create EnterCodeLabel
            app.EnterCodeLabel = uilabel(app.UIFigure);
            app.EnterCodeLabel.HorizontalAlignment = 'right';
            app.EnterCodeLabel.Position = [5 425 73 22];
            app.EnterCodeLabel.Text = 'Enter Code: ';

            % Create EnterCodeEditField
            app.EnterCodeEditField = uieditfield(app.UIFigure, 'text');
            app.EnterCodeEditField.ValueChangedFcn = createCallbackFcn(app, @EnterCodeEditFieldValueChanged, true);
            app.EnterCodeEditField.Position = [12 404 100 22];

            % Create TextArea
            app.TextArea = uitextarea(app.UIFigure);
            app.TextArea.Position = [1 1 150 365];
            app.TextArea.Value = {'Reminder:'; ''; '1. Zeros on the data does not mean it is 0. It means World Bank opendata did not provide that year''s info'; ''; '2. Export as txt file will overwrite the previous file unless you rename your previous file.'; ''; '3. TXT file will be exported to the same path as the app is with name "SavedData.txt".'; ''; '4. DO NOT write code when there is no graph plotted.'; ''; '5. Follow the format of code instruction provided by World Bank'};
        end
    end

    methods (Access = public)

        % Construct app
        function app = FianlPrj3_exported

            % Create and configure components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end