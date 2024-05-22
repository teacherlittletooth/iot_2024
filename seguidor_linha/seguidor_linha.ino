// CONSTANTES
#define LDR1 A4
#define LDR2 A5
#define LED1 6
#define LED2 7
#define MOTOR1 8
#define MOTOR2 9


// VARIÁVEIS
int ldr1Read, ldr2Read, ldr1Map, ldr2Map;
int value = 50;

//Função de interrupção
void interrupt()
{
  Serial.println("SOLTOU O BOTAUM!");
}

void setup()
{
  Serial.begin(9600);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  attachInterrupt(0, interrupt, FALLING);
  
  //Teste dos leds
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
}

void loop()
{
  delay(150);
    
  ldr1Read = analogRead(LDR1);
  ldr2Read = analogRead(LDR2);
  
  ldr1Map = map( ldr1Read, 679, 6, 100, 0 );
  ldr2Map = map( ldr2Read, 679, 6, 100, 0 );
  
  if(ldr1Map < value) {
  	digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, HIGH);
  }
  
  if(ldr2Map < value) {
  	digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(MOTOR1, HIGH);
    digitalWrite(MOTOR2, LOW);
  }
  
  if(ldr1Map > value && ldr2Map > value) {
  	digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(MOTOR1, HIGH);
    digitalWrite(MOTOR2, HIGH);
  }
  
  Serial.println( (String)"LDR1: " + ldr1Map );
  Serial.println( (String)"LDR2: " + ldr2Map );
}
