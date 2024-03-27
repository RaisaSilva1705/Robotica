//#include <Ultrasonic.h>

const int echoPin = 6; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)

const int pinoBuzzer = 10; //PINO DIGITAL EM QUE O BUZZER ESTÁ CONECTADO

//Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS
//long microsec = 0; 
//float distanciaCM = 0;

void setup(){
  Serial.begin(9600); 
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAÍDA (ENVIA)
  pinMode(pinoBuzzer, OUTPUT); //DECLARA O PINO COMO SENDO SAÍDA
}
void loop(){
  //microsec = ultrasonic.timing();
  //distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  int duracao;
  int distancia;
  float velocidade = 0.024;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  duracao = pulseIn(echoPin, HIGH);
  duracao = duracao/2;

  distancia = duracao * velocidade;

  //ledDistancia();
  Serial.print(distancia);
  Serial.println(" cm");
  delay(500);


  if(distancia > 30){
    tone(pinoBuzzer, 1500);//ACIONA O BUZZER    
  }
  else{
    noTone(pinoBuzzer);
  }
}

// void ledDistancia() {
//   noTone(pinoBuzzer);
//   delay(500);
//   if (distanciaCM <= 30){
//     tone(pinoBuzzer,1500);//ACIONA O BUZZER
//   }
//   if (distanciaCM >= 70 && distanciaCM < 150){
//     tone(pinoBuzzer,1500);//ACIONA O BUZZER
//   }
//   else{//SENÃO, FAZ
//     noTone(pinoBuzzer);//BUZZER PERMANECE DESLIGADO
//   }
// }