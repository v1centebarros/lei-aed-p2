clc
clear all;
%10000 pessoas e 10000 nªmec varia
tempos=load("tempos_10000_por10000mec.txt");
n_mec=tempos(:, 1);
n_persons = tempos(:, 2);
time_insert=tempos(1:end, 3:6);
time_creation=tempos(1:end,7);
time_search=tempos(1:end, 8:11);
time_depth=tempos(1:end, 12:end);

%figure(1)
subplot(2,2,1)
histogram(time_creation,1000,"EdgeColor","none","FaceAlpha",1);hold on
title("Tree Creation Time histogram for 10000 persons and 10000 experiments")
% xlim([0.5 3* 10^-3])
legend("All Indices")
xlabel("Time")
ylabel("Number of Occurrences");
grid on
hold off
set(gca,"GridLineStyle",":", "GridAlpha",1)

%figure(2)
subplot(2,2,2)
histogram(time_insert(:,1),1000,"EdgeColor","none","FaceAlpha",1);hold on
histogram(time_insert(:,2),1000,"EdgeColor","none","FaceAlpha",1);hold on
histogram(time_insert(:,3),1000,"EdgeColor","none","FaceAlpha",1);hold on
histogram(time_insert(:,4),1000,"EdgeColor","none","FaceAlpha",1);hold on
% xlim([0 0.7 * 10^-3])
title("Tree Insert Time histogram for 10000 persons and 10000 experiments")
legend("Name", "Zip Code", "Telephone Number", "Social Security Number")
xlabel("Time")
ylabel("Number of Occurrences");
set(gca,"GridLineStyle",":", "GridAlpha",1)
grid on
hold off;

%figure(3)
subplot(2,2,3)
histogram(time_search(:,1),1000,"EdgeColor","none","FaceAlpha",1);hold on
histogram(time_search(:,2),1000,"EdgeColor","none","FaceAlpha",1);hold on
histogram(time_search(:,3),1000,"EdgeColor","none","FaceAlpha",1);hold on
histogram(time_search(:,4),1000,"EdgeColor","none","FaceAlpha",1);hold on
set(gca,"GridLineStyle",":", "GridAlpha",1)
title("Tree Search Time histogram for 10000 persons and 10000 experiments")
legend("Name", "Zip Code", "Telephone Number", "Social Security Number")
xlabel("Time")
ylabel("Number of Occurrences");
grid on
hold off;

% figure(4)
subplot(2,2,4)
histogram(time_depth(:,1),10000,"EdgeColor","none","FaceAlpha",1);hold on;
histogram(time_depth(:,2),10000,"EdgeColor","none","FaceAlpha",1);hold on;
histogram(time_depth(:,4),10000,"EdgeColor","none","FaceAlpha",1);hold on;
histogram(time_depth(:,3),10000,"EdgeColor","none","FaceAlpha",1);hold on;
xlim([0 1.7* 10^-3])
set(gca,"GridLineStyle",":", "GridAlpha",1)
title("Tree depth Time histogram for 10000 persons and 10000 experiments")
legend("Name", "Zip Code","Social Security Number", "Telephone Number")
xlabel("Time")
ylabel("Number of Occurrences");
grid on
hold off;