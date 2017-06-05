#include <SPI.h>
#include <U8g2lib.h>
//#include <Keypad.h>

U8G2_ST7920_128X64_1_8080 u8g2(U8G2_R0,23,22,25,24,27,26,28,29,37,U8X8_PIN_NONE,35);

//char customKey=0;
//const byte ROWS = 5; //four rows
//const byte COLS = 4; //four columns
//char hexaKeys[ROWS][COLS] = {
//  {'1','2','3'},
//  {'4','5','6'},
//  {'7','8','9'},
//  {'*','0','#'}
//};
//byte rowPins[ROWS] = {45, 47, 49, 51}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {39, 41, 43}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
//Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
//char customKey=0;

void setup() {
//  Serial.begin(9600);
  // put your setup code here, to run once:
  u8g2.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,20,"Enter DOB");

    //customKey = customKeypad.getKey();
    //if (customKey) { //o meaning that this key came from previous locker input
      // Serial.println(String(customKey));
      // u8g2.drawStr(0,60,String(customKey));
   // }
  } while ( u8g2.nextPage() );
  //delay(1000);

}
