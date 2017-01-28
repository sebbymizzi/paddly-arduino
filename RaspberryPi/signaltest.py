import requests
import RPi.GPIO as GPIO
import time

channel = 14

response = requests.get('https://paddly.herokuapp.com/locker?unit=Sam')
data = response.json()
print(data);

GPIO.setmode(GPIO.BCM)
GPIO.setup(channel, GPIO.OUT)
GPIO.output(channel, True);
print("sending...");
time.sleep(1);
GPIO.output(channel, False);
GPIO.cleanup();
