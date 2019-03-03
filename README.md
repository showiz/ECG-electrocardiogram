# ECG-electrocardiogram
Este es un proyecto de Electrocardiograma creado con un microprocesador PIC18F4550

This is a ECG Project created with a PIC18F4550 microprocessor

ESPAÑOL:
Construcción de un Electrocardiograma:

1) Obtención de la señal: Las formas de obtener una señal son llamadas ´Derivaciones´ dado el lugar en donde se colocarán los electrodos. Para este proyecto se utilizará la Derivacion Unipolar (Ver imagen DerivacionUnipolar.jpg), la cual consta de obtener la señal de tres partes: 

- aVR = Muestra del brazo derecho
- aVL = Muestra del brazo izquierdo
- aVF = Muestra del pie izquierdo

2) Electrodos: La tensión del corazón ronda los 1mV. Para esta parte del proyecto es posible utilizar cualquier tipo de electrodo que posea un área significativa para la obtención de la señal. En algunos casos es posible crear electrodos con modedas que su composición sea mayor o igual a 95% de cobre. 

3) Circuito de amplificación: El circuito de amplificación (véase imagen  CircuitoAmplificacion.jpg) está preocupado de tomar la señal proveniente de la derivación seleccionada para poder amplificarla y enviarla a la siguiente etapa dedicada a filtrar la señal. Este circuito cuenta con un amplificador operacional TL072 que funcionará como inversor amplificando negativamente la señal en caso de exceso de tensión que pueda afectar al usuario. Es necesario recordar que la tensión proveniente de la derivación es del orden de 1mV, por lo que amplificarla ayudará al microprocesador a obtener una muestra más clara de las pulsaciones del corazón.

4) Circuito de filtrado: Este circuito (véase imagen CircuitoDeFiltrado.jpg) permite filtrar las frecuencias que no leerá el microprocesador. Se considera un rango de trabajo entre 0.05 y 100Hz de tal manera de obtener las muestras de las oscilaciones correspondientes al funcionamiento del corazón. Advertencia: Podrá observase en algunos casos la señal proveniente de la red eléctrica (para algunos paises: 50 ~ 60Hz)

5) Circuito de protección: Este circuito (véase imagen ProteccionDelPic.jpg) está encargado de proteger la integridad del microprocesador PIC18F4550 antes posibles variaciones de tensión. Los rangos de trabajo del microprocesador deben estar entre 0 y 5V, por lo que cualquier tensión mayor podría dañar al microprocesador.

6) Código de adquisición de datos: Para adquirir los datos que serán leidos por el microprocesador (véase código CodPic) se utilizarán las librerías de lectura de USB para C. Estas permitirán obtener en un ordenador las lecturas en formato de texto (.txt) que podrán ser graficadas luego en Matlab. Para cargar al microprocesador con el código se utiliza el ´Pickit2 Programmer´.

7) Código de filtro digital FIR: Para eliminar el ruido que la línea de transmisión añade (En este caso 50Hz) se utiliza un filtro digital (véase código FIR). Este procedimiento se realiza después de obtener la señal, y cuyo filtrado corresponde a un código en Matlab. 

ENGLISH:

Building an ECG:

1) Caught signals: The ways to obtain a signal are called 'Derivations' given the place where the electrodes will be placed. For this project the Unipolar Derivation will be used (See image DerivacionUnipolar.jpg), which consists of obtaining the signal in three parts:

- aVR = Sample of right arm
- aVL = Sample of left arm
- aVF = Sample of left foot

2) Electrodes: The heart tension is around 1mV. For this part of the project it is possible to use any type of electrode that has a significant area for obtaining the signal. In some cases it is possible to create electrodes with coins that their composition is greater than or equal to 95% copper.

3) Amplification circuit: The amplification circuit (see image CircuitoAmplificacion.jpg) is concerned to take the signal from the selected branch to amplify it and send it to the next stage dedicated to filter the signal. This circuit has an operational amplifier TL072 that will work as an inverter, negatively amplifying the signal in case of excess voltage that could affect the user. It is necessary to remember that the voltage coming from the derivation is of the order of 1mV, so amplifying it will help the microprocessor to obtain a clearer sample of the pulsations of the heart.

4) Filtering circuit: This circuit (see image CircuitoDeFiltrado.jpg) allows to filter the frequencies that the microprocessor will not read. A working range between 0.05 and 100Hz is considered in order to obtain the samples of the oscillations corresponding to the functioning of the heart. Warning: In some cases, the signal coming from the electricity network may be observed (for some countries: 50 ~ 60Hz)

5) Protection circuit: This circuit (see image ProteccionDelPic.jpg) is responsible for protecting the integrity of the PIC18F4550 microprocessor before possible voltage variations. The working ranges of the microprocessor must be between 0 and 5V, so any higher voltage could damage the microprocessor.

6) Data acquisition code: In order to acquire the data that will be read by the microprocessor (see CodPic code), the USB reading libraries for C will be used. These will allow reading on a computer to be obtained in text format (.txt) that can be graphed later in Matlab. To load the microprocessor with the code, the'Pickit2 Programmer' is used.

7) FIR digital filter code: To eliminate the noise that the transmission line adds (In this case 50Hz) a digital filter is used (see FIR code). This procedure is performed after obtaining the signal, and whose filtering corresponds to a code in Matlab.
