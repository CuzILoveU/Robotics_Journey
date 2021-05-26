clc; clear all;
%fclose(instrfind)
%%
s = serialport('COM3', 9600);
% s = serial('COM3', 'BaudRate', 9600)
% fopen(s)
readline(s)

%%
dlen = 10;
tmicros = zeros(dlen, 1);
seq = zeros(dlen,1);
voltage = zeros(dlen,1);

flush(s)

for ii = 1:10 

data1 = readline(s)

data = str2num(data1)
tmicros(ii) = data(1)*1*10^-6;
seq(ii) = data(2);
voltage(ii) = data(3);


end

%% medium intensitu
writeline(s, "0.5 1")
%%  low intensity
writeline(s, "0.01 1")
%% high intensity
writeline(s, "0.9 1")
%% off
writeline(s, "0.9 0")
%%
%fget(s)