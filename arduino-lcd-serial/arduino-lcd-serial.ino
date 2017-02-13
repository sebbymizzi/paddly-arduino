
#include <LiquidCrystal.h>
#include <Keypad.h>
#include<EEPROM.h>

// coding for display.
LiquidCrystal lcd (13,12,11,10,9,8);


void setup() {
  Serial.begin(9600);
  lcd.begin(4,16);
  lcd.setCursor (0,1);
  lcd.print("     HELLO");
  delay (3000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("welcome to");
  
  lcd.setCursor (0,1);
  lcd.print ("    PADDLY");
  delay (3000);
  lcd.clear ();
  
  lcd.setCursor (0,0);
  lcd.print ("please enter");
  lcd.setCursor (0,1);
  lcd.print ("your lock number");


}

char password[4];
char pass[4],pass1[4];
int i=0;
char customKey=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Hello, World!");
  delay(1000);
}
