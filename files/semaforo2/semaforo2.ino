// C++ code
//
int ledVermelho = 6;
int ledAmarelo = 10;
int ledVerde = 8;

void setup()
{  
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
 
}

void loop()
{
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);

  delay(5000);
    
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, HIGH);
      
  delay(5000);
      
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVerde, LOW);
    
  delay(2000);
 }
  
