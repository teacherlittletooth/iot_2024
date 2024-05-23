//VARIÁVEIS
int cm = 0;
int cmTwo = 0;

//CONSTANTES
#define ULTRA 7
#define TRIGGER 6
#define ECHO 5
#define SOM 9

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

long readUltrasonicDistanceTwo(int triggerPin, int echoPin)
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH);
}

void parking1()
{
  if( cmTwo < 300 && cmTwo >= 220 ){
  	tone(SOM, 840);
    delay(400);
    noTone(SOM);
    delay(400);
  }
  if( cmTwo < 220 && cmTwo >= 160 ){
  	tone(SOM, 840);
    delay(250);
    noTone(SOM);
    delay(250);
  }
  if( cmTwo < 160 && cmTwo >= 80 ){
  	tone(SOM, 840);
    delay(100);
    noTone(SOM);
    delay(100);
  }
  if( cmTwo < 80 ){
  	tone(SOM, 840);
  }
  if( cmTwo >= 300 ){
  	noTone(SOM);
  }
}

void parking2()
{
  switch( cmTwo ){
  	case 220 ... 300:
    	tone(SOM, 840);
        delay(400);
        noTone(SOM);
    	delay(400);
    	break;
    case 160 ... 219:
    	tone(SOM, 840);
        delay(250);
        noTone(SOM);
    	delay(250);
    	break;
    case 80 ... 159:
    	tone(SOM, 840);
        delay(100);
        noTone(SOM);
    	delay(100);
    	break;
    case 0 ... 79:
    	tone(SOM, 840);
    	break;
    default:
    	noTone(SOM);
        break;
  }
}

void parking3()
{
   int time = (cmTwo * 2) - 200;
   if( cmTwo < 300 && cmTwo >= 80 ){
  	 tone(SOM, 840);	
     delay(time);
     noTone(SOM);
     delay(time);
   }
   if( cmTwo < 80 ) {
     tone(SOM, 840);
   }
   if( cmTwo >= 299 ){
     noTone(SOM);
   }
}


void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(SOM, OUTPUT);
}

void loop()
{
  //Chamando função de 'estacionamento'
  //parking1();
  //parking2();
  parking3();
  
  // Medindo a distância em 'cm'
  cm = 0.01723 * readUltrasonicDistance(ULTRA, ULTRA);
  cmTwo = 0.01723 *  readUltrasonicDistanceTwo(TRIGGER, ECHO);
  
  Serial.print("Sensor 1: ");
  Serial.print(cm);
  Serial.print(" cm | ");
  Serial.print("Sensor 2: ");
  Serial.print(cmTwo);
  Serial.println(" cm");
  delay(100);
}
