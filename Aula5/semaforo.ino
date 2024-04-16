//Constantes
#define VERDE_A 7
#define AMARELO_A 6
#define VERMELHO_A 5
#define VERDE_B 4
#define AMARELO_B 3
#define VERMELHO_B 2

void setup()
{
  pinMode(VERDE_A, OUTPUT);
  pinMode(AMARELO_A, OUTPUT);
  pinMode(VERMELHO_A, OUTPUT);
  pinMode(VERDE_B, OUTPUT);
  pinMode(AMARELO_B, OUTPUT);
  pinMode(VERMELHO_B, OUTPUT);
}

void loop()
{
  digitalWrite(VERDE_A, HIGH);
  digitalWrite(VERMELHO_B, HIGH);
  delay(5000);
  
  digitalWrite(VERDE_A, LOW);
  digitalWrite(AMARELO_A, HIGH);
  delay(3000);
  
  digitalWrite(AMARELO_A, LOW);
  digitalWrite(VERMELHO_A, HIGH);
  digitalWrite(VERMELHO_B, LOW);
  digitalWrite(VERDE_B, HIGH);
  delay(5000);
  
  digitalWrite(AMARELO_B, HIGH);
  digitalWrite(VERDE_B, LOW);
  delay(3000);
  
  digitalWrite(AMARELO_B, LOW);
  digitalWrite(VERMELHO_A, LOW);
}
