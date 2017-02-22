import serial
import json
import pprint
pp = pprint.PrettyPrinter(indent=4)

ser = serial.Serial('/dev/ttyACM0', 9600)
waitingForPin = False;
locker="10";
pin="0000";

def checkData():
    print("checking");
    with open('data.json') as json_data:
        data = json.load(json_data)
        pp.pprint(data);
        found = False;

        lockername = "SAM00" + locker;
        print("testing for locker " + lockername);
        print("testing for pin " + pin);

        for item in data:
            isbooked = item["booked"];
            islocker = item["locker"];
            ispincode = str(item["pincode"]);
            if isbooked == True and islocker == lockername and ispincode == pin:
                print("found");
                found = True;
        
        if found:
            ser.write(bytes('1', 'ascii'));
            print("OK")
        else:
            ser.write(bytes('2', 'ascii'));
            print("NOT OK");


while 1 :
    value = ser.readline().decode("ascii");
    if waitingForPin:
        pin = ''.join(e for e in value if e.isalnum());
        checkData();
    else:
        locker = ''.join(e for e in value if e.isalnum());

    waitingForPin = not waitingForPin
    print(value);

