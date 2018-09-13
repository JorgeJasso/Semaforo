#define verde 13
#define amarillo 8
#define rojo 7
#define blanco 2
#define botonPeatonal 0
#define perilla A1
#define verdePeaton 6
#define rojoPeaton 5

boolean estadoBotonPeatonal = LOW; //Almacena el estado del botón peatonal, es decir si ha sido pulsado o no.
int valorPerilla=0; //Almacena el valor de la perilla

void setup() {
  pinMode (verde, OUTPUT);
  pinMode (amarillo, OUTPUT);
  pinMode (rojo, OUTPUT);
  pinMode (blanco, OUTPUT); //Este pin servirá para mantener encedido un led siempre que el botón peatonal pueda ser pulsado y se apagara cuando aun no haya pasado el tiempo minimo del semáforo estando en verde.
  pinMode (verdePeaton, OUTPUT);
  pinMode (rojoPeaton, OUTPUT);
  pinMode (botonPeatonal, INPUT);
  Serial.begin(9600); //Se establece la velocidad de la comunicación serial en 9600
}

void loop() {
  valorPerilla=analogRead(perilla); //Lee el valor de la perilla y lo almacena en valorPerilla
  Serial.print("Valor de la perilla: ");
  Serial.println(valorPerilla);
  while(digitalRead(botonPeatonal)==LOW){ //Se repetira siempre y cuando el bóton peatonal este pulsado
      estadoBotonPeatonal=LOW; //Indica que el botón peatonal ha sido precionado
  }
  if(estadoBotonPeatonal==LOW){ //Si el botón es igual a LOW significa que el botón ha sido pulsado
    digitalWrite(blanco,LOW); //Apaga el led para indicar que no sé puede presionar el botón peatonal
    digitalWrite(verde, LOW); //Apaga el verde para posteriormente encender el amarillo
    digitalWrite(amarillo, HIGH); //Se enciende el amarillo
    delay(6000); //Espera 6 segundos 
    digitalWrite(amarillo,LOW); //Apaga el amarillo
    /*
      El ciclo permite que el amarillo prenda y apague a mayor velocidad, esto para indicar a los vehículos que el rojo ya se encenderá
    */
    for(int iteracion=0;iteracion<4;iteracion++){
      delay(500);
      digitalWrite(amarillo, HIGH); 
      delay(500);
      digitalWrite(amarillo,LOW);   
    }
    digitalWrite(rojoPeaton, LOW);
    digitalWrite(rojo, HIGH); //Enciende el rojo
    digitalWrite(verdePeaton, HIGH); //Le da el paso al peaton
    delay(10000); //Espera 10 segundos
    digitalWrite(rojo,LOW); //Apaga el rojo
    digitalWrite(verdePeaton, LOW);
    digitalWrite(rojoPeaton, HIGH); //Impide el paso del peaton
    digitalWrite(verde, HIGH); //Se vuelve a prender el verde que se mantendra asi hasta que otro peaton pida el cruce.
    delay(valorPerilla*10); //Hace una espera del valor de la perilla multiplicado por 10, es decir si el valor de la perilla es de 1000 la espera será de 10 segundos. Esto para darle un tiempo minimo al verde
    digitalWrite(blanco, HIGH); //Una vez trasncurrido este tiempo el led blanco enciende para indicar que ya se puede precionar de nuevo el botón peatonal.
    estadoBotonPeatonal=HIGH; //le asigna el valor de HIGH para decir que ya no esta en un estado de pulsado
  }
}
