% 1st method

% n = -5:5;
% x = zeros(1, length(n));


% for i =1:length(n)
%     if n(i) >= 0
%         x(i) = n(i);
%     endif
% end

% stem(n, x, "filled");


% 2nd method

% n = -5:5;
% x = n;

% for i =1:length(n)
%     if n(i) >= 0
%         x(i) = n(i);
%     else
%         x(i) = 0;
%     endif
% end

% stem(n, x, "filled");


% 3rd Method

% n = -5:5;
% x = max(0, n);
% stem(n, x, "filled");



pause