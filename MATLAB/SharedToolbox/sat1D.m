function x = sat1D(x, xLow, xHigh)

if  x < xLow
    x = xLow;
elseif x > xHigh
    x = xHigh;
else
    % x = x;
end

end