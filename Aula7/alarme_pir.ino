// Constantes
const int PIR = 2; //#define PIR 2
const int LED = 3;
const int SOM = 4;
const int BTN = 5;

// Variáveis
bool key = false;
String status = "OFF";
bool activated = false;
int count = 10;

void setup()
{
  // Inicialização do Monitor Serial
  Serial.begin(9600);
  
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(SOM, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop()
{
  delay(250);
  
  if( !key ){
  	if( digitalRead(PIR) == 1 ){
	  activated = true;
  	}
  }
  
  if( activated ){
    status = (String)"ARMADO..." + count;
    count--;
    digitalWrite(LED, HIGH);
    tone(SOM, 600);
    delay(150);
    digitalWrite(LED, LOW);
    noTone(SOM);
    delay(600);
  }
  
  if( count == -1 ){
    ativar();
  }
  
  if( key ){
    alarme();
  }
  
  if( digitalRead(BTN) == 0 ){
    desativar(); 
  }
  
  Serial.println( status );
}

//////////////////////////////////////
void alarme()
{
  digitalWrite(LED, HIGH);
  tone(SOM, 800);
  delay(250);
  digitalWrite(LED, LOW);
  //noTone(SOM);
  delay(250);
}

void ativar()
{
  key = true;
  status = "ATIVADO!";
  activated = false;
  count = 10;
}

void desativar()
{
  key = false;
  status = "OFF";
  activated = false;
  count = 10;
  noTone(SOM);
}
