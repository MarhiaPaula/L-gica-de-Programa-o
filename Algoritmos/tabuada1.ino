int tabuada;
int contador;
int resultado;
  
void setup()
{
  Serial.begin(9600);
  
  Serial.println("Olá, seja bem vindo, digite o numero da tabuada que desejar, por favor");
  while(!Serial.available());
  tabuada = Serial.parseInt();
  
  for(contador = 1; contador <= 10;contador++){
    resultado = tabuada * contador;
    
    Serial.print(tabuada);
    
    Serial.print("*");
    
    Serial.print(contador);
    
    Serial.print("=");
    
    Serial.println(resultado);
    
  }  }

void loop()
{
 //sem instruçoes 
}