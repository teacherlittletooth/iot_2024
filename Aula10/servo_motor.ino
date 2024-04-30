#include <Servo.h>

// CONSTANTES
#define MOTOR1 2
#define MOTOR2 3
#define POT1 A5
#define POT2 A4
#define BTN 4

// VARIÁVEIS
Servo servo1, servo2;
int pot1Read, pot2Read, pot1Map, pot2Map;

void setup()
{
  //Monitor Serial
  Serial.begin(9600);
  
  //Inicialização de servo motores
  servo1.attach( MOTOR1 );
  servo2.attach( MOTOR2 );
  
  //Configurando demais portas
  pinMode( POT1, INPUT );
  pinMode( POT2, INPUT );
  pinMode( BTN, INPUT_PULLUP );
  
  //Teste de inicialização
  servo1.write( 180 );
  servo2.write( 180 );
  delay( 1500 );
  servo1.write( 0 );
  servo2.write( 0 );
}

void loop()
{
  delay(50);
  
  //Lógica para detecção de clique no botão
  if( digitalRead(BTN) == 0 ){
  	servo1.write( 90 );
    servo2.write( 90 );
    delay(500);
  }
  
  //Lendo valores nas portas analógicas
  pot1Read = analogRead( POT1 );
  pot2Read = analogRead( POT2 );
  
  //Ajustando leitura
  pot1Map = map( pot1Read, 1023, 682, 180, 0 );
  pot2Map = map( pot2Read, 1023, 682, 180, 0 );
  
  //Lançando o valor ajustado para o servo motor
  servo1.write( pot1Map );
  servo2.write( pot2Map );
  
  //Mostrando valores de leitura no MS
  Serial.println( (String)"M1: " + pot1Map );
  Serial.println( (String)"M2: " + pot2Map );
}
