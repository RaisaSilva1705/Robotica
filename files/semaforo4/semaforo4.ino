// C++ code
//
int ledVermelho = 6;
int ledAmarelo = 10;
int ledVerde = 8;

int ledPedVermelho = 3;
int ledPedVerde = 2;


void setup()
{  
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  pinMode(ledPedVermelho, OUTPUT);
  pinMode(ledPedVerde, OUTPUT);
 
}

void loop()
{
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);

  digitalWrite(ledPedVermelho, LOW); 
  digitalWrite(ledPedVerde, HIGH);

  delay(5000)  ;   
  for (int i=0; i < 10; i++){
    digitalWrite(ledPedVerde, LOW);
    delay(500);
    digitalWrite(ledPedVerde, HIGH);
    delay(500);
  }
    
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, HIGH);

  digitalWrite(ledPedVermelho, HIGH);
  digitalWrite(ledPedVerde, LOW);      
  
  delay(5000);
      
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVerde, LOW);

  digitalWrite(ledPedVermelho, HIGH);
  digitalWrite(ledPedVerde, LOW);

  delay(2000);
 }
  
