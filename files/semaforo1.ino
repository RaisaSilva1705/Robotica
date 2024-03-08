int ledVermelho = 6;
int ledAmarelo = 10;
int ledVerde = 8;

int ledPedVermelho = 2;
int ledPedVerde = 3;

int botao = 4;

int estadoBotao;
int faseSemaforo;
int estadoAnteriorBotao;

int tempoPisca;
int estadoPisca;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  pinMode(ledPedVermelho, OUTPUT);
  pinMode(ledPedVerde, OUTPUT);

  pinMode(botao, INPUT);

  faseSemaforo = 1;

  estadoAnteriorBotao = digitalRead(botao);
  
  tempoPisca = 0;
  estadoPisca = HIGH;
}

void loop() {
  // put your main code here, to run repeatedly:
   estadoBotao = digitalRead(botao);

  // Alterar ao soltar o botão (estadoBotao == LOW) && (estadoAnteriorBotao == HIGH))
  if ((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)) {
    if(faseSemaforo < 4){
      faseSemaforo = faseSemaforo + 1;      
    } else {
      faseSemaforo = 1;
    }
  }

  estadoAnteriorBotao = estadoBotao;

  if (faseSemaforo == 1){ //SEMAFORO VERMELHO LIGADO
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);

    digitalWrite(ledPedVermelho, LOW);
    digitalWrite(ledPedVerde, HIGH);

  }

  if (faseSemaforo == 2){ //SEMAFORO VERMELHO PEDESTRE PISCANDO
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, LOW);

      tempoPisca = tempoPisca + 1;
      
      if (tempoPisca == 10){
        estadoPisca = !estadoPisca;
        tempoPisca = 0;
      }

      digitalWrite(ledPedVermelho, estadoPisca);
      digitalWrite(ledPedVerde, LOW);
    }

  if (faseSemaforo == 3){ //SEMAFORO VERDE LIGADO
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);

    digitalWrite(ledPedVermelho, HIGH);
    digitalWrite(ledPedVerde, LOW);
  }

  if (faseSemaforo == 4){ //SEMAFORO AMARELO LIGADO
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVerde, LOW);

      digitalWrite(ledPedVermelho, HIGH);
      digitalWrite(ledPedVerde, LOW);
    }

  delay(50);
}
