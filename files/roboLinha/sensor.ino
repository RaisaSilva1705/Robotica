
//Definição dos pinos dos sensores
#define pin_S1 7
#define pin_S2 6
bool Sensor1 = 0;
bool Sensor2 = 0;

void setup(){
  Serial.begin(9600);
  //Setamos os pinos dos sensores como entrada
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);
}
void loop(){
  //Neste processo armazenamos o valor lido pelo sensor na variável que armazena tais dados.
  Sensor1 = digitalRead(pin_S1);
  Sensor2 = digitalRead(pin_S2);
  Serial.println("Sensor1: ");
  Serial.println(Sensor1);
  Serial.println("Sensor2: ");
  Serial.println(Sensor2);
  Serial.println("-----------------");
  delay(1000);
}
