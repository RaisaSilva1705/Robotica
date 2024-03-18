int pinLed[9] = {11,10,9,8,7,6,5,4,3};
int numLed;
int pinPot = A0;
void setup() {
  // put your setup code here, to run once:
  int x;

  for (x = 0; x <= 9; x++){
    pinMode(pinLed[x], OUTPUT); 
  }
  
  pinMode(pinPot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int potValue = analogRead(pinPot);
  int delayTime = map(potValue, 0, 1023, 50, 1000);
  
  for (numLed = 0; numLed <= 8; numLed++){
    digitalWrite(pinLed[numLed], HIGH);
    delay(delayTime);
  }

    for (numLed = 8; numLed >= 0 ; numLed--){
    digitalWrite(pinLed[numLed], LOW);
    delay(delayTime);
  }
}
