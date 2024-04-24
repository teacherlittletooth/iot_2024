// CONSTANTES
#define LDR A5
#define RELE 2

// VARIÁVEIS
int ldrRead;
int ldrMap;

void setup()
{
  //Monitor Serial
  Serial.begin(9600);
  
  pinMode(LDR, INPUT);
  pinMode(RELE, OUTPUT);
}

void loop()
{
  //Delay para dar uma atrasada no loop
  delay(250);
  
  //Lançando valor de leitura do sensor
  //para uma variável
  ldrRead = analogRead(LDR);
  
  //Mapeando o valor de leitura padrão para
  //um valor específico
  ldrMap = map( ldrRead, 679, 6, 100, 0 );
  
  //Lógica para ligar/desligar o relé
  if( ldrMap > 80 ){
    digitalWrite(RELE, HIGH); 
  } else {
  	digitalWrite(RELE, LOW);
  }
  
  //Saída de dados para o Monitor Serial
  Serial.println( (String)"Luminosidade: " + ldrMap + " %");
}
