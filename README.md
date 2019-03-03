# ECG-electrocardiogram
Este es un proyecto de Electrocardiograma creado con un microprocesador PIC18F4550
This is a ECG Project created with a PIC18F4550 microprocessor

Construcción de un Electrocardiograma:

1) Obtención de la señal: Las formas de obtener una señal son llamadas ´Derivaciones´ dado el lugar en donde se colocar+an los electrodos. Para este proyecto se utilizará la Derivacion Unipolar (Ver imagen DerivacionUnipolar.jpg), la cual consta de obtener la señal de tres partes: 

- aVR = Muestra del brazo derecho
- aVL = Muestra del brazo izquierdo
- aVF = Muestra del pie izquierdo

2) Electrodos: La tensión del corazón ronda los 1mV. Para esta parte del proyecto es posible utilizar cualquier tipo de electrodo que posea un área significativa para la obtención de la señal. En algunos casos es posible crear electrodos con modedas que su composición sea mayor o igual a 95% de cobre. 

3) Circuito de amplificación: El circuito de amplificación (véase imagen  CircuitoAmplificacion.jpg) está preocupado de tomar la señal proveniente de la derivación seleccionada para poder amplificarla y enviarla a la siguiente etapa dedicada a filtrar la señal. Este circuito cuenta con un amplficador operacional TL072 que funcionará como inversor amplificando negativamente la señal en caso de exceso de tensión que pueda afectar al usuario. Es necesario recordar que la tensión proveniente de la derivación es del orden de 1mV, por lo que amplificarla ayudará al microprocesador a obtener una muestra más clara de las pulsaciones del corazón.

4) Circuito de filtrado: Este circuito (véase imagen CircuitoDeFiltrado.jpg) permite filtrar las frecuencias que no leerá el microprocesador. Se considera un rango de trabajo entre 0.05 y 100Hz de tal manera de obtener las muestras de las oscilaciones correspondientes al funcionamiento del corazón. Advertencia: Podrá observase en algunos casos la señal proveniente de la red eléctrica (para algunos paises: 50 ~ 60Hz)

5) Circuito de protección: Este circuito (véase imagen ProteccionDelPic.jpg) está encargado de proteger la integridad del microprocesador PIC18F4550 antes posibles variaciones de tensión. Los rangos de trabajo del microprocesador deben estar entre 0 y 5V, por lo que cualquier tensión mayor podría dañar al microprocesador.
