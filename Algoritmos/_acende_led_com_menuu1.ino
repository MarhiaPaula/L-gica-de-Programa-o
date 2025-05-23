int ledVerde = 13;
int ledAmarelo = 11;
int ledVermelho = 12;
int opcao;//indica opcao invalida


void mostrarMenu (){
  Serial.println("Menu de Controle de LEDs:");
  Serial.println("Escolha uma opçao");
  Serial.println(" 1- Ligar Led Verde  ");
  Serial.println(" 2- Desligar Led Verde  ");
  Serial.println(" 3- Ligar Led Amarelo  ");
  Serial.println(" 4- Desligar Led Amarelo");
  Serial.println(" 5- Ligar Led Vermelho ");
  Serial.println(" 6- Desligar Led Vermelho ");
  Serial.println(" 7- Ligar Todos os Leds ");
  Serial.println(" 8- Desligar Todos os Leds ");
  Serial.println(" 0- Sair ");
}

void setup() {
  Serial.begin(9600);

  
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  
  do {
    mostrarMenu();

    //Espera até que tenha os dados disponíveis 
    while (Serial.available() == 0) {}
    opcao = Serial.parseInt();

    switch (opcao) {
      case 1:
        digitalWrite(ledVerde, HIGH);
        Serial.println("LED Verde Ligado");
        break;
      
      case 2:
        digitalWrite(ledVerde, LOW);
        Serial.println("LED Verde Desligado");
        break;
      
      case 3:
        digitalWrite(ledAmarelo, HIGH);
        Serial.println("LED Amarelo Ligado");
        break;
      
      case 4:
        digitalWrite(ledAmarelo, LOW);
        Serial.println("LED Amarelo Desligado");
      	break;
      
      case 5:
        digitalWrite(ledVermelho, HIGH);
        Serial.println("LED Vermelho Ligado");
      	break;
      
      case 6:
        digitalWrite(ledVermelho, LOW);
        Serial.println("LED Vermelho Desligado");
      	break;
      
      case 7:
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledAmarelo, HIGH);
        digitalWrite(ledVermelho, HIGH);
        Serial.println("Todos os LEDs foram ligados");
      	break;
      
       case 8:
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, LOW);
        Serial.println("Todos os LEDs foram desligados");
      	break;
      
      case 0:
      Serial.println("Obridado por jogar, volte sempre");
      break;
      
      default:
      Serial.println("Escolha uma das opçoes validas de 1 ao 8");
      
      
    }
  }
    while(opcao != 0);
}

  void loop() {}