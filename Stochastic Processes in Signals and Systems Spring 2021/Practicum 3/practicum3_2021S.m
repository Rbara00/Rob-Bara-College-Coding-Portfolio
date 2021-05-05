clear
close all

N_Sensors = 100;                % number of sensors in each trial
N_Trials = 10000;               % number of trials
range = [50 56];                % range of measured pollution level 
hist_range = [50:.1:56];        % range of histogram plot

for iloop = 1:N_Trials
    score = randi(range, N_Sensors, 1);
    score_ave(iloop) = sum(score)/N_Sensors;
end

hist_result = hist(score_ave, hist_range);

figure(1)
plot(score,'o')
hold on
plot(score_ave(end)*ones(N_Sensors,1),'r');
xlabel('Index of sensors'); ylabel('Measured pollution level')

figure(2)
plot(score_ave)
xlabel('Index of trials');ylabel('Average pollution level')

figure(3)
plot(hist_range, hist_result/N_Trials,'-','LineWidth',2)
xlim(range)
xlabel('Average pollution level'); ylabel('Relative frequency')
