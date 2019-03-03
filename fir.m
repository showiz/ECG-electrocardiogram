load dat.txt; % carga datos en el archivo "dat.txt", vector de columna 
x = dat; %transpone y copia datos a "x" (vector de fila) 
x = 5*x*100/(255*1000*156); % convierte códigos del ADC a milivolts

%diseñar filtro

Fs = 1000; %
f = [45 50]; %rango de efecto del filtro 
a = [1 0]; %amplitudes deseadas en las bandas 
rp = 1; %ripple en dB en la banda de paso 
rs = 40; %ripple en la banda de rechazo 
dev = [(10^(rp/20)-1)/(10^(rp/20)+1) 10^(-rs/20)]; %desviaciones 
[N, fo, ao, w] = firpmord(f, a, dev, Fs); %estimar orden del filtro 
b1 = firpm(N, fo, ao, w); %cálculo de coeficientes del filtro 
y = filter(b1, 1, x) %aplicar filtro
%graficar 
n1 = 62000; n2 = 66000; %muestras seleccionadas para los gráficos
n = [n1 : n2]; 
t = n/800; %paso en el tiempo 
subplot (2,1,1); 
plot(t,x(n),'b'); %cuadricula de 2x1 posición 1 
ylim([0 0.0035]);
xlabel('seg'); ylabel ('milivolts'); title('Señal original'); 
%hold on;
subplot (2,1,2), plot(t, y(n),'g');%cuadricula de 2x1 posición 2

axis([n1/800 n2/800 0 0.005]); 
ylim([0 0.0035]);
xlabel('seg'); ylabel ('milivolts'); 
title('Señal filtrada (FIR)')
