t=-5:5

hold on;
% * Unit Impulse Signal
unit_impulse=t==0;
stem(t,unit_impulse)

% * Unit Step Signal
unit_step=t>=0;
stem(t, unit_step);

% * Ramp Signal
ramp = (t>=0).*t;
stem(t,ramp)

% * Sinusoidal Signal
t=0:0.01:20
sin_signal=sin(t)
plot(t,sin_signal)

% * Cosine Signal
t=0:0.01:20
cos_signal=cos(t);
plot(t,cos_signal);

pause