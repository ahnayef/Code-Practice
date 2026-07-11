t=-10:10

% Unit Impulse Signal:
imp = (t==0);
% Original: delta[n]
stem(t,imp);
% Delayed: delta[n-3]
stem(t-3,imp);
% Advanced: delta[n+2]
stem(t+2,imp);


% Unit Step Signal:
u = (t>=0);
% Original: u[n]
stem(t,u);
% Delayed: u[n-4]
stem(t-4,u);
% Advanced: u[n+3]
stem(t+3,u);


% Ramp Signal:
r = max(0,t);
% Original: r[n]
stem(t,r);
% Delayed: r[n-2]
stem(t-2,r);
% Advanced: r[n+2]
stem(t+2,r);


% QnA

% Q: What is the fundamental difference between a time delay and a time advance?
% Ans: A time delay shifts the signal to the right (future), while a time advance shifts the signal to the left (past).

% Q: How does shifting affect the overall shape of the signal?
% Ans: Shifting does not change the shape of the signal; it only changes the position of the signal along the time axis.

% Q: Does time shifting change the amplitude of the signal?
% Ans: No, time shifting does not change the amplitude of the signal.

% Q: What practical, real-world meaning can be assigned to a delayed signal?
% Ans: A delayed signal can represent a system's response to an input that arrives later, such as the delay in communication systems or the time it takes for a physical process to occur.
