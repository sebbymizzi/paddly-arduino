#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <SPI.h>

int inPin = 4;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    val = digitalRead(inPin);   // read the input pin
    if(val == HIGH) {
      Serial.println("received!");
    }
}
