Práctica Semáforo


Sistema que simula un Semáforo Interactivo usando Arduino. Este muestra un conjunto de semáforos
que cambian de verde a ámbar a rojo, luego de un período de tiempo establecido, utilizando el sistema
de cuatro estados de los semáforos en México. Este se extiende para incluir un conjunto de luces
y un bóton peatonal para solicitar cruzar la calle. 
Cuando llega el peatón y se dispone a cruzar pulsa el botón peatonal que encuentra en la parte baja del
semáforo, este reconoce la orden y cierra el paso de los vehículos para que el viandante pueda cruzar con
seguridad hasta el otro lado de la calle, se cuenta con un led que indica cuando ya se puede solicitar el paso.
Una vez que se acaba el tiempo éstipulado para que el peatón cruce, ese semáforo permanecerá abierto para
mejorar la movilidad de los vehículos.
El sistema contiene una perilla para controlar el tiempo mínimo en que el semáforo vehícular va a durar en verde.


Para poner en marcha el proyecto se debe contar con un Arduino en el cual se carge el programa y un protoboard para
armar el circuito que contará con 4 leds (verde,amarillo,rojo y blanco), un botón y un potenciometro para regular el 
tiempo minimo del verde encendido.