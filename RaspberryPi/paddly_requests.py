import requests
import time
import json as js

while True:
    print("connecting...");
    response = requests.get('https://paddly.herokuapp.com/api/1/lockers/mr3bLvh03g')
    data = response.json()
    print(data);
    with open('data.json', 'w') as f:
        js.dump(data, f);    

    response = requests.get('https://paddly.herokuapp.com/api/1/bookings/mr3bLvh03g')
    data = response.json()
    print(data);
    with open('data_bookings.json', 'w') as f:
        js.dump(data, f);    
    
    time.sleep(3);

