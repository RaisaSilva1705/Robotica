int ledR = 7;
int ledA = 6;
int ledV = 5;
int val;      

void setup(){
  pinMode(ledR,OUTPUT);
  pinMode(ledA,OUTPUT);
  pinMode(ledV,OUTPUT);
}

void loop(){
  val=analogRead(A0);
  if (val>=0 && val<255){
    digitalWrite(ledR, HIGH);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, LOW);
  }
  
  if (val>=255 && val<511){
    digitalWrite(ledR, LOW);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledV, LOW);
  }
  
  if (val>=511 && val<767){
    digitalWrite(ledR, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, HIGH);
  }
  }
