int valor = 0;
 
void setup() {
Serial.begin(9600);
}
 
void loop() {
valor = analogRead(A0);
Serial.println(valor);
delay(100);
}
