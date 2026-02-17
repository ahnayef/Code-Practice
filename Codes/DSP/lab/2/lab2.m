clc;

t = 0:0.01:20;
s1 = sin(t);
c1 = cos(t);
t1 = tan(t);
axis([-5 20 -2 2]);

hold on;

plot(t,s1,'r');
plot(t,c1,'g');
plot(t,t1,'b');


plot([0,0], ylim, 'k'); % vertical line
plot(xlim, [0,0], 'k'); % horizontal line
hold off;