// piano_v1.ino

// Definição das frequencias por nota
#define T_C 262 // Dó
#define T_D 294 // Ré
#define T_E 330 // Mi
#define T_F 349 // Fá
#define T_G 392 // Sol
#define T_A 440 // Lá
#define T_B 493 // Sí

// Declarando os pinos por nota (botão)
const int C = 10;
const int D = 9;
const int E = 8;
const int F = 7;
const int G = 6;
const int A = 5;
const int B = 4;

// Declarando os pinos para o LED e BUZZ 
const int BUZZ = 11;
const int LED = 13;

void setup(){
  pinMode(LED, OUTPUT); // LED = saída
  digitalWrite(LED,LOW);

  pinMode(C, INPUT); // Dó = entrada
  digitalWrite(C,HIGH);
  
  pinMode(D, INPUT); // Ré = entrada
  digitalWrite(D,HIGH);
  
  pinMode(E, INPUT); // Mi = entrada
  digitalWrite(E,HIGH);
  
  pinMode(F, INPUT); // Fá = entrada
  digitalWrite(F,HIGH);
  
  pinMode(G, INPUT); // Sol = entrada
  digitalWrite(G,HIGH);
  
  pinMode(A, INPUT); // Lá = entrada
  digitalWrite(A,HIGH);
  
  pinMode(B, INPUT); // Sí = entrada
  digitalWrite(B,HIGH);
}

void loop(){
  while(digitalRead(C) == LOW){ // ENQUANTO botão é apertado
    tone(BUZZ,T_C); // BUZZ emite som na frequencia específica
    digitalWrite(LED,HIGH); // LED acende 
  }

  while(digitalRead(D) == LOW){
    tone(BUZZ,T_D);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(E) == LOW){
    tone(BUZZ,T_E);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(F) == LOW){
    tone(BUZZ,T_F);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(G) == LOW){
    tone(BUZZ,T_G);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(A) == LOW){
    tone(BUZZ,T_A);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(B) == LOW){
    tone(BUZZ,T_B);
    digitalWrite(LED,HIGH);
  }

  noTone(BUZZ); // Enquanto nenhum botão é apertado, BUZZ não emite som.
  digitalWrite(LED,LOW); // nenhum LED é ativado
}
