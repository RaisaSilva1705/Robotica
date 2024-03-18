qint x = 10;
int y = 15;
int z = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.begin("Utilizado para debugar o codigo")
  Serial.print("Valores em binario: ");
  Serial.print("\nx:");
  Serial.print(x, BIN);

  Serial.print("\ny:");
  Serial.print(y, BIN);
  
  Serial.print("\nz:");
  Serial.print(z, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:

 }
