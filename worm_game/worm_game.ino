#include <Adafruit_LiquidCrystal.h>

//CONSTANTES
#define DOWN 7
#define RIGHT 6
#define UP 5
#define LEFT 4

//VARIÁVEIS
String icon = "*";
int col = 0, row = 0;
Adafruit_LiquidCrystal lcd(0);

//Função de interrupção
void interrupt0()
{
  Serial.println("Apertou");
}

void interrupt1()
{
  Serial.println("Soltou");
}

void setup()
{
  attachInterrupt(0, interrupt0, RISING);
  attachInterrupt(1, interrupt1, FALLING);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  
  lcd.print("*** INTERNET ***");
  lcd.setCursor(0, 1);
  lcd.print("** DAS COISAS **");
  delay(1000);
}

void loop()
{
  delay(5000);
  lcd.clear();
  lcd.setCursor(col, row);
  lcd.print(icon);
  
  if( digitalRead(UP) == 0 ) {
  	row = 0;
  }
  
  if( digitalRead(DOWN) == 0 ) {
  	row = 1;
  }
  
  if( digitalRead(RIGHT) == 0 ) {
  	col++;
    if(col > 15){
      col = 15;
    }
  }
  
  if( digitalRead(LEFT) == 0 ) {
  	col--;
    if(col < 0){
      col = 0;
    }
  }
  
  Serial.print("col = ");
  Serial.print(col);
  Serial.print(" | row = ");
  Serial.println(row);
}
