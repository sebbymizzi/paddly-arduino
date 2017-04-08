void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);;
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   openLocker(22, 5);
}

void openLocker(int from_pin, int locker_no) {
   digitalWrite(from_pin, HIGH && (locker_no & B01000000));
   digitalWrite(from_pin+1, HIGH && (locker_no & B00100000));
   digitalWrite(from_pin+2, HIGH && (locker_no & B00010000));
   digitalWrite(from_pin+3, HIGH && (locker_no & B00001000));
   digitalWrite(from_pin+4, HIGH && (locker_no & B00000100));
   digitalWrite(from_pin+5, HIGH && (locker_no & B00000010));
   digitalWrite(from_pin+6, HIGH && (locker_no & B00000001));
}
