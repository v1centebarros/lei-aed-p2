clc
clear all

dados=load("profundidade_2021.txt");
%dados=load("profundidade_097787.txt");
%dados=load("profundidade_103823.txt");
n_persons = dados(:, 2);
depth=dados(1:end,3:end);


figure(1)
semilogx(n_persons,depth,".-");hold on
title("Maximum tree depth")
legend("Name", "Zip Code", "Telephone Number", "Social Security Number")
ylabel("Profundidade")
xlabel("Número de pessoas")
grid on
hold off