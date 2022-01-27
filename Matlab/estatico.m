clc
clear all;

%dados=load("profundidade_1000.txt");
%dados=load("profundidade_100.txt");
%dados=load("profundidade_500.txt");
dados=load("profundidade_10000.txt");
depth=dados(1:end,3:end);

figure(2)
bar(unique(depth(:,1))-0.1,nonzeros(histcounts(depth(:,1))),0.1);hold on
bar(unique(depth(:,2)),nonzeros(histcounts(depth(:,2))),0.1);hold on
bar(unique(depth(:,3))+0.1,nonzeros(histcounts(depth(:,3))),0.1);hold on
bar(unique(depth(:,4))+0.2,nonzeros(histcounts(depth(:,4))),0.1);hold on
title("Tree Depth")
legend("Name", "Zip Code", "Telephone Number", "Social Security Number")
xlabel("Profundidade")
ylabel("Number of occurrences")
grid on
hold off


maxdepth=max(depth);
mindepth=min(depth);
mediadepth=mean(depth);
desviodepth=std(depth);

indexes=["name","Zip code","Telephone Number", "Social Security Number"];
fprintf("%25s |%12s |%12s |%12s |%12s \n", "Tipo de dados", "minimo","máximo","média", "desvio");
for k=1:4
    fprintf("%25s |%12d |%12d |%e |%e \n", indexes(k), mindepth(k), maxdepth(k), mediadepth(k),desviodepth(k))
end