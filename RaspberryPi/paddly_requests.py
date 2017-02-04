import requests
import time
import json as js

while True:
    print("connecting...");
    response = requests.get('https://paddly.herokuapp.com/locker?unit=Sam')
    data = response.json()
    print(data);
    js
    with open('data.json', 'w') as f:
        js.dump(data, f);    

    time.sleep(3);

