f="DRIVEN_POS.csv";
opts = detectImportOptions(f);
T = readtable(f, opts);
A = table2array(T);

I = polyfit(A(1,:), A(2,:), 1);
O = polyfit(A(1,:), A(3,:), 1);
H = tf(O,I)

subplot(2,1,1);
plot(T,"X", "CH1")
title('Step Input (V vs. s)')

subplot(2,1,2); 
plot(T, "X", "CH2")
title('DC Motor Step Response (V vs. s)')