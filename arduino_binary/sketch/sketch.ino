int openLock = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   openLocker(2, openLock);
}

void openLocker(int from_pin, int locker_no) {
   digitalWrite(from_pin+7, HIGH && (locker_no & B10000000));
   digitalWrite(from_pin+6, HIGH && (locker_no & B01000000));
   digitalWrite(from_pin+5, HIGH && (locker_no & B00100000));
   digitalWrite(from_pin+4, HIGH && (locker_no & B00010000));
   digitalWrite(from_pin+3, HIGH && (locker_no & B00001000));
   digitalWrite(from_pin+2, HIGH && (locker_no & B00000100));
   digitalWrite(from_pin+1, HIGH && (locker_no & B00000010));
   digitalWrite(from_pin, HIGH && (locker_no & B00000001));
}

