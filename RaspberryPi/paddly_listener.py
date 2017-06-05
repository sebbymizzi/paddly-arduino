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
    with open('data_booking.json') as json_data:
        data = json.load(json_data)
        pp.pprint(data);
        found = 0;

        print("testing for authId " + locker);
        print("testing for pin " + pin);

        for item in data:
            isbooked = item["authId"];
            islocker = item["authPin"];
            ispincode = str(item["pincode"]);
            if islocker == locker and ispincode == pin:
                print("found")
                found = item["locker"]

	ser.write(bytes(found, 'ascii'))
	print("OK")


while 1 :
    value = ser.readline().decode("ascii");
    if waitingForPin:
        pin = ''.join(e for e in value if e.isalnum());
        checkData();
    else:
        locker = ''.join(e for e in value if e.isalnum());

    waitingForPin = not waitingForPin
    print(value);

