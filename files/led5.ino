int pinLed[9] = {11,10,9,8,7,6,5,4,3};
int numLed;
char caracter;

void setup() {
  // put your setup code here, to run once:  
  int x;

  for (x = 0; x < 9; x++){
    pinMode(pinLed[x], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  caracter = ' ';
  numLed = 0;
  while (caracter != 'x'){
    digitalWrite(pinLed[numLed], LOW);
    numLed++;
    if (numLed > 8){
      numLed = 0;
    }
    digitalWrite(pinLed[numLed], HIGH);

    if (Serial.available()){
      caracter = Serial.read(); 
    }
    delay(50);
  }

  delay(5000);
}