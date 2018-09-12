#define verde 13
#define amarillo 8
#define rojo 7

void setup() {
  pinMode (verde, OUTPUT);
  pinMode (amarillo, OUTPUT);
  pinMode (rojo, OUTPUT);
}

void loop() {
    digitalWrite(verde, HIGH); //Enciende el verde
    delay(10000); //Espera 10 segundos
    digitalWrite(verde,LOW); //Apaga el verde
    delay(10000); //Espera 10 segundos

    digitalWrite(amarillo, HIGH); //Enciende el amarillo
    delay(10000); //Espera 10 segundos
    digitalWrite(amarillo,LOW); //Apaga el amarillo
    delay(10000); //Espera 10 segundos

    digitalWrite(rojo, HIGH); //Enciende el rojo
    delay(10000); //Espera 10 segundos
    digitalWrite(rojo,LOW); //Apaga el rojo
    delay(10000); //Espera 10 segundos
}
