#define verde 13
#define amarillo 8
#define rojo 7
#define botonPeatonal 0
#define perilla A1

boolean estadoBotonPeatonal = LOW; //Almacena el estado del botón peatonal, es decir si ha sido pulsado o no.
int valorPerilla=0; //Almacena el valor de la perilla

void setup() {
  pinMode (verde, OUTPUT);
  pinMode (amarillo, OUTPUT);
  pinMode (rojo, OUTPUT);
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
    digitalWrite(verde, LOW); //Apaga el verde para posteriormente encender el amarillo
    digitalWrite(amarillo, HIGH); //Se enciende el amarillo
    delay(10000); //Espera 10 segundos 
    digitalWrite(amarillo,LOW); //Apaga el amarillo   
    digitalWrite(rojo, HIGH); //Enciende el rojo
    delay(10000); //Espera 10 segundos
    digitalWrite(rojo,LOW); //Apaga el rojo
    digitalWrite(verde, HIGH); //Se vuelve a prender el verde que se mantendra asi hasta que otro peaton pida el cruce.
    delay(valorPerilla*10); //Hace una espera del valor de la perilla multiplicado por 10, es decir si el valor de la perilla es de 1000 la espera será de 10 segundos. Esto para darle un tiempo minimo al verde
    estadoBotonPeatonal=HIGH; //le asigna el valor de HIGH para decir que ya no esta en un estado de pulsado
  }
}
