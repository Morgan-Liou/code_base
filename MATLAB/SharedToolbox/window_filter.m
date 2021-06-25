function [dataWindow, windowCycle] = window_filter(dataRaw, dataWindow, k_windowSize, windowCycle)

if 0 == windowCycle
    windowCycle = 1;
    dataWindow = dataRaw;
elseif windowCycle < k_windowSize
    windowCycle = windowCycle + 1;
    dataWindow = (dataWindow * (window_cycle - 1) + dataRaw) / windowCycle;
else
    % windowCycle = windowCycle;
    dataWindow = (dataWindow * (k_windowSize - 1) + dataRaw) / k_windowSize;
end

end