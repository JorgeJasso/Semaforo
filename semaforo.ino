#define verde 13
#define amarillo 8
#define rojo 7
#define botonPeatonal 0

boolean estadoBotonPeatonal = LOW; //Almacena el estado del botón peatonal, es decir si ha sido pulsado o no.

void setup() {
  pinMode (verde, OUTPUT);
  pinMode (amarillo, OUTPUT);
  pinMode (rojo, OUTPUT);
  pinMode (botonPeatonal, INPUT);
}

void loop() {
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
    estadoBotonPeatonal=HIGH; //le asigna el valor de HIGH para decir que ya no esta en un estado de pulsado
  }
}
