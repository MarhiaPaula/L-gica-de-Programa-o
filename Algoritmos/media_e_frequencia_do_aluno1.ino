// C++ code
//Calcule a média entre DUAS notas.
//Verifique se o aluno foi APROVADO.
//Aprovado se média é MAIOR OU IGUAL A 6 e SE A frequência É MAIOR OU IGUAL 75%.
//Caso contrário, exiba se foi reprovado por nota.
//Exiba se foi REPROVADO por frequência.
//Exiba se foi REPROVADO frequência e média da nota .
//Se a média for exatamente 10 e a frequencia for 100, exiba: "Parabéns! Nota máxima!".

int nota1 = 0;
int nota2 = 10;
float frequencia = 75%

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int media = (nota1 + nota2) / 2;
  
  Serial.println();
  Serial.println("digite a primeira nota:");
  while(!Serial.available());
  float nota1 = Serial.parseFloat();
  
  Serial.println("digite a segunda nota:");
  while(!Serial.available());
  float nota2 = Serial.parseFloat();
  
  Serial.println("digite a frequencia:");
  while(!Serial.available());
  int frequencia = Serial.parseInt();
  
    
    
 if (media >=6 && media <=9 && frequencia >= 7.5){
  Serial.println("Aluno foi aprovado");
  }
  
  else if (media == 10 && frequencia ==100){
   Seral.println("Aluno foi aprovado apenas por nota");
  } 
  
  else if (media <=4 && frequencia >=75 ){
   Serial.println("Aluno foi reprovado apenas por nota"); 
  } 
  
  else if (media >=7 && frequencia <=74 ){
   Serial.prinln("Aluno foi reprovado por frequencia ");
  }
  
  else if (media <=3 || frequencia <=74){
   Serial.println("Aluno reprovado por nota e frequencia");
  }
  
  