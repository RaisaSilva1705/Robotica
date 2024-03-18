int pinLed[9] = {11,10,9,8,7,6,5,4,3};
int numLed;

void setup() {
  // put your setup code here, to run once:
  int x;

  for (x = 0; x <= 9; x++){
    pinMode(pinLed[x], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (numLed = 0; numLed <= 8; numLed++){
    digitalWrite(pinLed[numLed], HIGH);
    delay(300);
  }

    for (numLed = 8; numLed >= 0 ; numLed--){
    digitalWrite(pinLed[numLed], LOW);
    delay(300);
  }
}
