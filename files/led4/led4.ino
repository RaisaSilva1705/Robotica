int pinLed[9] = {11,10,9,8,7,6,5,4,3};
int numLed;

void setup() {
  // put your setup code here, to run once:
  int x;

  for (x = 0; x < 9; x++){
    pinMode(pinLed[x], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  numLed = 0;
  while (numLed < 9){
    digitalWrite(pinLed[numLed], HIGH);
    delay(300);
    numLed++;  
  }
    

  numLed = 8; 
  
  while (numLed > 0){
    digitalWrite(pinLed[numLed], LOW);
    delay(300);
    numLed --;
  }       
}

