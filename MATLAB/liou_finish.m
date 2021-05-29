%% Reminder: program finishes
% pop %
f = warndlg('MATLAB EOP','Notification');

% sound %
load splat
n_sound = 3;
delta_sound = 0.5;
for i_sound = 1 : n_sound
    sound(y,Fs)
    pause(delta_sound)
end
clear n_sound delta_sound i_sound;
%% Debug
dbclear if error;