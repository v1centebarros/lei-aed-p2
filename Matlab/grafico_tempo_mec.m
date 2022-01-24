clc
clear all;

%tempos=load("tempos_103823.txt");
tempos=load("tempos_097787.txt");
%tempos=load("tempos_2021.txt");

n_mec = tempos(:, 1);
n_persons = tempos(:, 2);
time_insert= tempos(1:end, 3:6);
time_creation=tempos(1:end,7);
time_search=tempos(1:end, 8:11);
time_depth=tempos(1:end, 12:end);

figure(1)
subplot(2,2,1)
loglog(n_persons,time_creation, ".-");hold on
title("Time Creation")
subtitle("Tempo médio de execução para cada n medido")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;

subplot(2,2,2)
loglog(n_persons,time_insert,".-");hold on
title("Time Insert")
subtitle("Tempo médio de execução para cada n medido")
legend("Name", "Zip Code", "Telephone Number", "Social Security Number")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;

subplot(2,2,3)
loglog(n_persons,time_search,".-");hold on
title("Time Search")
subtitle("Tempo médio de execução para cada n medido")
legend("Name", "Zip Code", "Telephone Number", "Social Security Number")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;

subplot(2,2,4)
loglog(n_persons,time_depth,".-");hold on
title("Time depth")
subtitle("Tempo médio de execução para cada n medido")
legend("Name", "Zip Code", "Telephone Number", "Social Security Number")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;