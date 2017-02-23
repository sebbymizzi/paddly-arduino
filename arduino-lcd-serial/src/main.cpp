#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
// coding for display.
LiquidCrystal lcd(13,12,11,10,9,8);

void requestLockerInput();

int locker1 = 14;
int locker2 = 15;
int locker3 = 16;
int locker4 = 17;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,4);
  pinMode(locker1, OUTPUT);
  pinMode(locker2, OUTPUT);
  pinMode(locker3, OUTPUT);
  pinMode(locker4, OUTPUT);
  
  digitalWrite(locker1, HIGH);
  digitalWrite(locker2, HIGH);
  digitalWrite(locker3, HIGH);
  digitalWrite(locker4, HIGH);
//  lcd.setCursor (0,1);
//  lcd.print("     HELLO");
//  delay (3000);
//  lcd.clear();
//  lcd.setCursor (0,0);
//  lcd.print ("Welcome to");
  
//  lcd.setCursor (0,1);
//  lcd.print ("    Paddly");
//  delay (3000);
  lcd.clear ();

  requestLockerInput();
}

int locker_delay = 5000;

bool requestingLocker;
bool requestingPin;
bool isWaitingForPi;

char pin[4];
char locker[1];
char pass[4],pass1[4];
int i=0;
char customKey=0;
const byte ROWS = 5; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {0, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 2, 3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void requestLockerInput() {
  isWaitingForPi = false;
  lcd.clear();
  requestingPin = false;
  requestingLocker = true;
  lcd.setCursor (0,0);
  lcd.print ("Enter locker no");
  lcd.setCursor (0,1);
}

void requestPinCode() {
  requestingLocker = false;
  lcd.setCursor(0, 1);
  lcd.print("  ");

  requestingLocker = false;
  i = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter pin code");
  lcd.setCursor(0, 1);
  requestingPin = true;
}

void turnOnLocker1() {
  digitalWrite(locker1, LOW);
  delay(locker_delay);
  digitalWrite(locker1, HIGH);
}
void turnOnLocker2() {
  digitalWrite(locker2, LOW);
  delay(locker_delay);
  digitalWrite(locker2, HIGH);
}
void turnOnLocker3() {
  digitalWrite(locker3, LOW);
  delay(locker_delay);
  digitalWrite(locker3, HIGH);
}
void turnOnLocker4() {
  digitalWrite(locker4, LOW);
  delay(locker_delay);
  digitalWrite(locker4, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(isWaitingForPi == true) {
    if (Serial.available()) {
      int reply = Serial.read() -'0';
      if(reply == 1) {
        lcd.clear();
        lcd.setCursor(0,0);
        String lockerno = String(locker[0]);
        if(lockerno == "1") {
            lcd.print("LOCKER 1 OPEN");
            turnOnLocker1();
        }
        if(lockerno == "2") {
            lcd.print("LOCKER 2 OPEN");
            turnOnLocker2();
        }
        if(lockerno == "3") {
            lcd.print("LOCKER 3 OPEN");
            turnOnLocker3();
        }
        if(lockerno == "4") {
            lcd.print("LOCKER 4 OPEN");
            turnOnLocker4();
        }
      } else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("INCORRECT PIN");
      }
      delay(3000);
      requestLockerInput();
    }
    return;
  }
    
  customKey = customKeypad.getKey();
  if (customKey && customKey != 'o') { //o meaning that this key came from previous locker input
    if(requestingLocker == true) {
      locker[0] = customKey;
      lcd.print(customKey);
      lcd.print(" ..OK");
      Serial.println(String(locker[0]));
      delay(1000);
      requestPinCode();
      return;
    }
    if (requestingPin == true)
    {
      pin[i]=customKey;
      lcd.print(customKey);
      if(i == 3) {
        //send to raspberry pi
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Please wait...");
        Serial.println(String(pin));
        isWaitingForPi = true;
      }
      i++;
      return;
    }
  }
}

