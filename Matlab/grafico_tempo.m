clc
clear all;

tempos=load("resultados.txt");

n_mec = tempos(:, 1);
n_persons = tempos(:, 2);
time_insert= tempos(1:end, 3:6);
time_creation=tempos(1:end,7);
time_search=tempos(1:end, 8:11);
time_depth=tempos(1:end, 12:end);


figure(1)
loglog(n_persons,time_creation)
hold on
title("Time Creation")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;

figure(2)
loglog(n_persons,time_insert)
hold on
title("Time Insert")
legend("tree1", "tree2", "tree3", "tree4")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;

figure(3)
loglog(n_persons,time_search)
hold on
title("Time Search")
legend("Tree 1", "Tree 2", "Tree 3", "Tree 4")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;

figure(4)
loglog(n_persons,time_depth)
hold on
title("Time depth")
legend("Tree 1", "Tree 2", "Tree 3", "Tree 4")
xlabel("Number of persons");
ylabel("Time(s)");
grid on
hold off;
