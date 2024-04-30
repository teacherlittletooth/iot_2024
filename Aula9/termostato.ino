// Constantes
#define TEMP A5
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED_COLD 6

// Variáveis
float tempRead;
float tempMap;

void setup()
{
  Serial.begin(9600);
  pinMode(TEMP, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED_COLD, OUTPUT);
}

void loop()
{
  delay(1000);
  tempRead = analogRead( TEMP );
  tempMap = map( tempRead, 358, 20, 125, -40 );
  
  //Caso fosse utilizado um sensor real:
  /*
  float voltage = (tempRead * 5) / 1023;
  tempMap = voltage / 0.010;
  */
  
  //switch não aceita tipo de dado float
  switch((int)tempMap) {
  	case -40 ... 0:
    	digitalWrite(LED_COLD, HIGH);
    	digitalWrite(LED1, LOW);
    	digitalWrite(LED2, LOW);
    	digitalWrite(LED3, LOW);
    	digitalWrite(LED4, LOW);
    	break;
    case 1 ... 15:
    	digitalWrite(LED_COLD, LOW);
    	digitalWrite(LED1, HIGH);
    	digitalWrite(LED2, LOW);
    	digitalWrite(LED3, LOW);
    	digitalWrite(LED4, LOW);
    	break;
    case 16 ... 30:
    	digitalWrite(LED_COLD, LOW);
    	digitalWrite(LED1, HIGH);
    	digitalWrite(LED2, HIGH);
    	digitalWrite(LED3, LOW);
    	digitalWrite(LED4, LOW);
    	break;
    case 31 ... 45:
    	digitalWrite(LED_COLD, LOW);
    	digitalWrite(LED1, HIGH);
    	digitalWrite(LED2, HIGH);
    	digitalWrite(LED3, HIGH);
    	digitalWrite(LED4, LOW);
    	break;
    case 46 ... 60:
    	digitalWrite(LED_COLD, LOW);
    	digitalWrite(LED1, HIGH);
    	digitalWrite(LED2, HIGH);
    	digitalWrite(LED3, HIGH);
    	digitalWrite(LED4, HIGH);
    	break;
    default:
    	digitalWrite(LED_COLD, LOW);
    	digitalWrite(LED1, HIGH);
    	digitalWrite(LED2, HIGH);
    	digitalWrite(LED3, HIGH);
    	digitalWrite(LED4, HIGH);
    	delay(250);
    	digitalWrite(LED1, LOW);
    	digitalWrite(LED2, LOW);
    	digitalWrite(LED3, LOW);
    	digitalWrite(LED4, LOW);
    	break;
  }
  
  Serial.println( (String)tempMap + " *C" );
}
