#include <Servo.h>
Servo motor;

const int buzzer = 4;
#include <Servo.h>


#define LED_VERMELHO 10
#define LED_VERDE 7
#define LED_AZUL_1 2
#define LED_AZUL_2 3
#define LED_AZUL_3 4
#define SERVO_PIN 12

Servo porta; 
int numeroSagrado;
int tentativas = 0;
int acertos = 0;
int portaAberta = false;

void setup() {
  
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL_1, OUTPUT);
  pinMode(LED_AZUL_2, OUTPUT);
  pinMode(LED_AZUL_3, OUTPUT);
  
  porta.attach(SERVO_PIN); 
  porta.write(0);
  Serial.begin(9600);
  randomSeed(analogRead(0)); 
  
  
  Serial.println("-----------------------------");
  Serial.println("Bem-vindo a Fortaleza do Dado Sagrado!");
  Serial.println("-----------------------------");
  Serial.println("Adivinhe o numero sagrado (1-6) para provar seu valor!");
  Serial.println("Acumule 3 acertos para abrir a Porta da Sabedoria!");
}

void loop() {
  if (!portaAberta) {
    
    numeroSagrado = random(1, 7);
    Serial.println("\nUm novo numero sagrado foi escolhido...");
    Serial.println("Digite seu palpite (1-6):");
    while (!Serial.available());
    int palpite = Serial.parseInt();
    while (Serial.available()) Serial.read();
    
    
    if (palpite < 1 || palpite > 6) {
      Serial.println("Palpite invalido! Digite um numero entre 1 e 6.");
    } else if (palpite == numeroSagrado) {
      
      acertos++;
      Serial.println("\n*** CORRETO! Voce e digno! ***");
      
      
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED_VERDE, HIGH);
        delay(300);
        digitalWrite(LED_VERDE, LOW);
        delay(300);
      }
      
      
      switch (acertos) {
        case 1:
          digitalWrite(LED_AZUL_1, HIGH);
          break;
        
        case 2:
          digitalWrite(LED_AZUL_2, HIGH);
          break;
        
        case 3:
          digitalWrite(LED_AZUL_3, HIGH);
          break;
      }
      
      
      if (acertos >= 3) {
        abrirPorta();
      }
    } else {
      
      Serial.println("\nINCORRETO! O numero sagrado era: " + String(numeroSagrado));
      Serial.println("Tente novamente, aventureiro!");
      
      
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED_VERMELHO, HIGH);
        delay(300);
        digitalWrite(LED_VERMELHO, LOW);
        delay(300);
      }
    }
    
    tentativas++;
    Serial.println("Acertos: " + String(acertos) + "/3 | Tentativas: " + String(tentativas));
  }
}

void abrirPorta() {
  portaAberta = true;
  Serial.println("\n*** PARABENS! ***");
  Serial.println("Voce provou seu valor e dominou a sabedoria do dado!");
  Serial.println("A Porta da Sabedoria se abre para voce!");
  
  
  for (int pos = 0; pos <= 90; pos++) {
    porta.write(pos);
    delay(15);
  }
  
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL_1, HIGH);
    digitalWrite(LED_AZUL_2, HIGH);
    digitalWrite(LED_AZUL_3, HIGH);
    delay(200);
    
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL_1, LOW);
    digitalWrite(LED_AZUL_2, LOW);
    digitalWrite(LED_AZUL_3, LOW);
    delay(200);
  }
  
  
  digitalWrite(LED_AZUL_1, HIGH);
  digitalWrite(LED_AZUL_2, HIGH);
  digitalWrite(LED_AZUL_3, HIGH);
}


