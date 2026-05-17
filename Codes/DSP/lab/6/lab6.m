n = -10:10;
x = zeros(1, length(n));

% Unit Ramp Signal
for i =1:length(n)
    if n(i) >= 0
        x(i) = n(i);
    endif
end

% Shifting
% stem(n-2,x,"filled");

% Reversal
% stem(-n-2,x,"filled");




% Unit Step Signal
% x_step = zeros(1, length(n));
% for i =1:length(n)
%     if n(i) >= 0
%         x_step(i) = 1;
%     endif
% end


% Unit Step Signal Negative Time Shifting by 5, time shifting, not amplitude shifting
x = zeros(1, length(n));
for i =1:length(n)
    if n(i) + 5 >= 0
        x(i) = 1;
    endif
end
stem(n, x, "filled");



% Mirror
% stem(-n,x,"filled");


pause