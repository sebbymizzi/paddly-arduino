#include <LiquidCrystal.h>
#include <Keypad.h>
#include<EEPROM.h>
#define led

// coding for display.
LiquidCrystal lcd (13,12,11,10,9,8);


void setup() {
  lcd.begin(4,16);
  lcd.setCursor (0,1);
  lcd.print("     HELLO");
  delay (3000);
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print ("Welcome to");
  
  lcd.setCursor (0,1);
  lcd.print ("    Paddly");
  delay (3000);
  lcd.clear ();

  requestLockerInput();

}

int locker1 = 0;
int locker2 = 1;
int locker3 = 2;
int locker4 = 3;

bool requestingLocker;
bool requestingPin;

char pin[4];
char locker[1];
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
  customKey = customKeypad.getKey();
  if (customKey) {
    if(requestingLocker == true) {
      locker[0] = customKey;
      requestPinCode();
    }
    if (requestingPin == true)
    {
      if(customKey == '#') {
        //send to raspberry pi
        
      } else {
        pin[i++]=customKey;
      }
      
       Serial.print(customKey);
       lcd.print(customKey);
    }
  }
}

void requestLockerInput() {
  requestingPin = false;
  requestingLocker = true;
  lcd.setCursor (0,0);
  lcd.print ("Enter locker no");
  lcd.setCursor (0,1);
}

void requestPinCode() {
  requestingLocker = false;
  customKey = ' ';
  lcd.setCursor(0, 1);
  lcd.print("  ");
  i = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter pin code");
  lcd.setCursor(0, 1);
  
  requestingPin = true;
}

void turnOnLocker1() {
  analogWrite(locker1, 255);
  delay(1000);
  analogWrite(locker1, 255);
}
void turnOnLocker2() {
  analogWrite(locker2, 255);
  delay(1000);
  analogWrite(locker2, 255);
}
void turnOnLocker3() {
  analogWrite(locker3, 255);
  delay(1000);
  analogWrite(locker3, 255);
}
void turnOnLocker4() {
  analogWrite(locker4, 255);
  delay(1000);
  analogWrite(locker4, 255);
}

