#include "Ultrasonic.h"
Ultrasonic ultrasonic(3, 2); 

const int ledVerde = 6;
const int ledAmarelo = 5;
const int ledVermelho = 4;

long microsec = 0; 
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  microsec = ultrasonic.timing();

  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);

  ledDistancia();
  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(500);
}

void ledDistancia() {

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  if (distanciaCM > 20) {
    digitalWrite(ledVerde, HIGH);
  }
  if (distanciaCM <= 20 and distanciaCM >= 10) {
    digitalWrite(ledAmarelo, HIGH);
  }
  if (distanciaCM < 10) { 
    digitalWrite(ledVermelho, HIGH);
  }
}
