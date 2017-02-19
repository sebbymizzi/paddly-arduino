Requirements to run arduino on raspberry pi
===========================================

sudo pip install -U platformio

platformio init

platformio init --board=uno

platformio run --target upload

platformio lib install "Keypad"
platformio lib install "LiquidCrystal"

platformio run --target upload
