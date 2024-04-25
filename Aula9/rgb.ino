// CONSTANTES
#define GREEN 9
#define BLUE 10
#define RED 11
#define GREEN_BTN 7
#define BLUE_BTN 6
#define RED_BTN 5

// VARIÁVEIS
int green = 0;
int blue = 0;
int red = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN_BTN, INPUT_PULLUP);
  pinMode(BLUE_BTN, INPUT_PULLUP);
  pinMode(RED_BTN, INPUT_PULLUP);
}

void loop()
{
  delay(250);
  
  if( digitalRead(RED_BTN) == 0 ){
  	red+=5; // red = red + 5;
    if( red > 255 ){
    	red = 0;
    }
  }
  
  if( digitalRead(BLUE_BTN) == 0 ){
  	blue+=5; // blue = blue + 5;
    if( blue > 255 ){
    	blue = 0;
    }
  }
  
  if( digitalRead(GREEN_BTN) == 0 ){
  	green+=5; // green = green + 5;
    if( green > 255 ){
    	green = 0;
    }
  }
  
  analogWrite( RED, red );
  analogWrite( BLUE, blue );
  analogWrite( GREEN, green );
  
  Serial.print( (String)"AZUL: " + blue + " | ");
  Serial.print( (String)"VERDE: " + green + " | ");
  Serial.println( (String)"VERMELHO: " + red );
}
