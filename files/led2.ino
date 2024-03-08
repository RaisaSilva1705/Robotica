int intervalo1; //Variavel Global
int intervalo2; //Variavel Global

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  intervalo1 = 500;
  intervalo2 = 1000;
}

void loop() {
  // put your main code here, to run repeatedly:
  //int intervalo1; Variavel Local
  //int intervalo2; Variavel Local
  //intervalo1 = 500;
  //intervalo2 = 1000;
  
  digitalWrite(10, HIGH);  
  digitalWrite(9, LOW);
  delay(intervalo1);

  digitalWrite(10, LOW);  
  digitalWrite(9, HIGH);
  delay(intervalo2);

}
