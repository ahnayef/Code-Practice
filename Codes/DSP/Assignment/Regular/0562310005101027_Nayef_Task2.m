n = -5:5;
x = zeros(1, length(n));



% 1st

% x=(n == 0);
% stem(n, x, "filled");


% 2nd

for i = 1:length(n)
    if n(i) == 0
        x(i) = 1;
    endif
end

stem(n, x, "filled");

pause;