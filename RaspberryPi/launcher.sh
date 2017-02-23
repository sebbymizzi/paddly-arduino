#!/bin/sh
# launcher.sh
# navigate to home directory, then to this directory, then execute python script, then back home

cd /
cd /home/pi/Documents/Developer/python/paddly-arduino/RaspberryPi
sudo forever stopall
sudo forever start -c python3 paddly_requests.py
sudo forever start -c python3 paddly_listener.py
cd /
