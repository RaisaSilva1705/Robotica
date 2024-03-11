int pinos[9] = {11,10,9,8,7,6,5,4,3};
int pinLed;

float min = 85;
float max = 1020;
float valorLDR;
float luminosidade;

void setup() {
  // put your setup code here, to run once:

  for (pinLed = 0; pinLed < 0; pinLed++){
    pinMode(pinos[pinLed], OUTPUT);
  }

  pinMode(A0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorLDR = digitalRead(A0);
  luminosidade = ((valorLDR - min) / (max - min)) * 10;
  luminosidade = (luminosidade - 10) * -1;

  for (pinLed = 0; pinLed < 9; pinLed++){
    if (pinLed < luminosidade){
      digitalWrite(pinos[pinLed], HIGH);
    } else {
      digitalWrite(pinos[pinLed], LOW);
    }
  }

  delay(500);
}
