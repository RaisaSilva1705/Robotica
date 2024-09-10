// sensorTemperatura.ino

// bibliotecas
#include <LiquidCrystal.h> // display

// declarando os pinos para conectar no display
const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// declarando os pinos declarados para o display
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

// definindo a saida analogica A0 para o sensor de temperatura
#define sen A0

// definindo valor da quantidade de amostras 
#define amostras 50

// declarando valor e temperatura como 0
float tp = 0.0, v = 0.0;

void setup(){
  Serial.begin(9600);

  // Declarando o sensor como uma entrada
  pinMode(sen, INPUT);
  
  // Formatação do display
  lcd.begin(16,2);          // 16 colunas e 2 linhas
  lcd.setCursor(0,0);       // colocando o cursor no começo
  lcd.print("Temperatura"); // escrevendo mensagem no display
  lcd.setCursor(6,1);       // colocando o cursor na coluna 7 e linha 2
  lcd.write(B11011111);     // código para imprimir "°" no display
  lcd.print("C");           // excrevendo mensagem no display 
}

void loop(){
  // tirar a média dos valores lidos
  float tp = mediaAmostras();
  
  // escrevendo o valor da temperatura no display
  lcd.setCursor(0,1); // primeira coluna, linha 2
  lcd.print(tp); // imprime o valor armazenado na variavel tp
  //delay(1000);
}

float mediaAmostras(){
  float total = 0;
  for (int i = 0; i < amostras; i++){
    total += ((analogRead(sen) * (5.0 / 1023)) / 0.01);
    delay(25);
  }
  total = total / amostras;
  return total;
}
