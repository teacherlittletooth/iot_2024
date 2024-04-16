//Constantes
 #define SOM 2
 #define BTN_DO 3
 #define BTN_RE 4
 #define BTN_MI 5
 #define BTN_FA 6
 #define BTN_SOL 7

//Variáveis;
int nota = 264;
int tempo = 150;

void setup()
{
  //Inicializando Monitor Serial
  Serial.begin(9600);
  
  pinMode(SOM, OUTPUT);
  pinMode(BTN_DO, INPUT_PULLUP);
  pinMode(BTN_RE, INPUT_PULLUP);
  pinMode(BTN_MI, INPUT_PULLUP);
  pinMode(BTN_FA, INPUT_PULLUP);
  pinMode(BTN_SOL, INPUT_PULLUP);
  
  for(int i=0; i<4; i++){
  	tone(SOM, nota);
  	delay(tempo);
  	noTone(SOM);
  	delay(tempo);
    nota += 100;
  }
}

void loop()
{
  Serial.println( (String)"DO = " + digitalRead(BTN_DO) );
  Serial.println( (String)"RE = " + digitalRead(BTN_RE) );
  Serial.println( (String)"MI = " + digitalRead(BTN_MI) );
  Serial.println( (String)"FA = " + digitalRead(BTN_FA) );
  Serial.println( (String)"SOL = " + digitalRead(BTN_SOL) );
  
  if(digitalRead(BTN_DO)==0) {
  	nota = 264;
  }
  if(digitalRead(BTN_RE)==0) {
  	nota = 300;
  }
  if(digitalRead(BTN_MI)==0) {
  	nota = 330;
  }
  if(digitalRead(BTN_FA)==0) {
  	nota = 352;
  }
  if(digitalRead(BTN_SOL)==0) {
  	nota = 396;
  }
  
  tone(SOM, nota);
  
  if(
    digitalRead(BTN_DO)==1 &&
    digitalRead(BTN_RE)==1 &&
    digitalRead(BTN_MI)==1 &&
    digitalRead(BTN_FA)==1 &&
    digitalRead(BTN_SOL)==1
  ) {
  	noTone(SOM);
  }
  
  delay(200);
}
