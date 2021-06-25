function y = sat2D(x, y, xLow, xHigh, yLow, yHigh)

if  x < xLow
    y = yLow;
elseif x > xHigh
    y = yHigh;
else
    % y = y;
end

end