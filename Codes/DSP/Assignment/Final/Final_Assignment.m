% * Unit Impulse Signal
t = -5:5;
unit_impulse = (t == 0);

figure;
stem(t, unit_impulse, 'filled');
grid on;

title('Unit Impulse Signal');
xlabel('Time');
ylabel('Amplitude');






% * Unit Step Signal
t = -5:5;
unit_step = (t >= 0);

figure;
stem(t, unit_step, 'filled');
grid on;

title('Unit Step Signal');
xlabel('Time');
ylabel('Amplitude');




% * Ramp Signal
t = -5:5;
ramp = (t >= 0).*t;

figure;
stem(t, ramp, 'filled');
grid on;

title('Ramp Signal');
xlabel('Time');
ylabel('Amplitude');




% * Sinusoidal Signal
t = 0:0.01:20;
sine_signal = sin(t);

figure;
plot(t,sine_signal)
grid on;

title('Sinusoidal Signal');
xlabel('Time');
ylabel('Amplitude');



% * Cosine Signal
t = 0:0.01:20;
cos_signal = cos(t);

figure;
plot(t,cos_signal)
grid on;

title('Cosine Signal');
xlabel('Time');
ylabel('Amplitude');





% x(t)=u(t)-2r(t)+7cos(t)​

t = -20:0.01:20;

% Individual signals
part1 = (t >= 0);
part2 = 2 * (t >= 0) .* t;
part3 = 7 * cos(t);

% Composite signal
composite_signal = part1 + part2 + part3;

% Part1: Unit Step Signal
figure;
plot(t, part1, 'LineWidth', 2);
grid on;
title('Part1: Unit Step Signal');
xlabel('Time');
ylabel('Amplitude');

% Part2: Ramp Signal
figure;
plot(t, part2, 'LineWidth', 2);
grid on;
title('Part2: Ramp Signal');
xlabel('Time');
ylabel('Amplitude');

% Part3: Cosine Signal
figure;
plot(t, part3, 'LineWidth', 2);
grid on;
title('Part3: Cosine Signal');
xlabel('Time');
ylabel('Amplitude');

% Composite Signal
figure;
plot(t, composite_signal, 'LineWidth', 2);
grid on;
title('Composite Signal');
xlabel('Time');
ylabel('Amplitude');






% Amplitude Scaling
t = -20:0.01:20;
part1 = (t >= 0);
part2 = 2 * (t >= 0) .* t;
part3 = 7 * cos(t);

composite_signal = part1 + part2 + part3;

% Amplitude Scaling
scaled_signal = 2 * composite_signal;

figure;
plot(t, composite_signal, 'LineWidth', 2);
hold on;
plot(t, scaled_signal, 'LineWidth', 2);
grid on;
title('Amplitude Scaled Signal');
xlabel('Time');
ylabel('Amplitude');





% Time Shifting
t = -20:0.01:20;
part1 = (t >= 0);
part2 = 2 * (t >= 0) .* t;
part3 = 7 * cos(t);
composite_signal = part1 + part2 + part3;

figure;
plot(t, composite_signal, 'LineWidth', 2);
hold on;
plot(t + 2, composite_signal, 'LineWidth', 2);
grid on;
title('Time Shifted Signal');
xlabel('Time');
ylabel('Amplitude');




% Time Reversal (Folding)
t = -20:0.01:20;
part1 = (-t >= 0);
part2 = 2 * (-t >= 0) .* -t;
part3 = 7 * cos(-t);
composite_signal = part1 + part2 + part3;


figure;
plot(t, composite_signal, 'LineWidth', 2);
grid on;
title('Time Reversed Signal');
xlabel('Time');
ylabel('Amplitude');




% Addition with another basic signal
t = -20:0.01:20;
part1 = (t >= 0);
part2 = 2 * (t >= 0) .* t;
part3 = 7 * cos(t);
composite_signal = part1 + part2 + part3;
addition = composite_signal + ((t >= 0) .* t);

figure;
plot(t, composite_signal, 'LineWidth', 2);
hold on;
plot(t, addition, 'LineWidth', 2);
grid on;
title('Addition with Ramp Signal');
xlabel('Time');
ylabel('Amplitude');


