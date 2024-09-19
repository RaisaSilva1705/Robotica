// Criado por REP JOE

// telegrafo_v1.ino

// Variaveis para o tempo que o botão fica pressionado 
unsigned long sinal_len, t1, t2;

#define BotaoCodigo 8               
#define LED 7

// Declarando uma variavel string chamada code 
String code = "";                 

void setup(){
  Serial.begin(9600); // Frequencia

  // Definindo os pinos como saída e entrada
  pinMode(BotaoCodigo, INPUT_PULLUP); 
  pinMode(LED, OUTPUT); 
}

void loop(){
  NextDotDash:
    while (digitalRead(BotaoCodigo) == HIGH) {}
    t1 = millis(); // Calcula o tempo que o botão foi pressionado 
    digitalWrite(LED, HIGH); // LED acende com o botão apertado

    while (digitalRead(BotaoCodigo) == LOW) {}
    t2 = millis(); // Calcula o tempo que o botão não está sendo pressionado
    digitalWrite(LED, LOW); // LED apaga quando o botão não está sendo apertado

    // Tempo total que o botão foi pressionado
    // Leva em consideração o anti-ressalto do botão
    sinal_len = t2 - t1; 
    
    if (sinal_len > 50){  
      code += readIO();  // Função para ler os traços e pontos
    }

    // Se o tempo entre o ponto ou traço digitado for maior que 
    // 0,5 segundos, o loop termina e recebe o próximo alfabeto
    while ((millis() - t2) < 500){           
      if (digitalRead(BotaoCodigo) == LOW){
        goto NextDotDash;
      }
    }
    convertor(); // Função para decifrar o código 
}

// Função para a leitura de pontos e traços
char readIO(){
  if (sinal_len < 600 && sinal_len > 50)
    return '.'; // Se o botão for precionado por menos de 0.6 s, será um ponto
  else if (sinal_len > 600)
    return '-'; // Se o botão for precionado por mais de 0.6 s, será um traço
}

// Função para converter os pontos e traços em alfabeto
void convertor()
{
  static String letras[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                             ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"
                            }; // Combinação das letras
  
  int i = 0;
  if (code == ".-.-.-"){ // Se tiver essa sequencia, será imprido "." na tela
    Serial.print(".");
  }
  else if (code == "-.-.-."){ // Se tiver essa sequencia, será imprimido " " na tela
    Serial.print(" ");
  }
  else{
    while (letras[i] != "E"){ // Ciclo para comparar as letras do array
      // Verifica a posição na variável “letras” e compara com 
      // o alfabeto chamado “código”, enquanto avança a variável i
      if (letras[i] == code){ 
        Serial.print(char('A' + i)); // Corre pelo alfabeto apartir do A até Z pela variavel i
        break; // E quando encontra a letra, sai do loop
      }
      i++;
    }
    if (letras[i] == "E"){ // Se nenhuma letra for encontrada
      Serial.println("");  // Então não fará nada
    }
  }
  code = ""; // reseta a variavel para que entre uma nova sequencia
}
