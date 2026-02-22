

% n = 0:10;
% y = sin(n);
% stem(n, y);

% hold on;
% for i = 0:1:10
%    y = sin(i);
%    stem(i, y);
% end
% hold off;



n = 0:5;
x = zeros(1, length(n)); %[0, 0, 0, 0, 0]

for i =1:length(n)
    x(i) = 2*n(i)+1;
    stem(n,x);
end

% Odd: 2n+1

pause