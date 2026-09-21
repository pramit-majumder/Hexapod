O#include <Servo.h>

Servo coxaServo1;
Servo femurServo1;
Servo tibiaServo1;

Servo coxaServo2;
Servo femurServo2;
Servo tibiaServo2;

Servo coxaServo3;
Servo femurServo3;
Servo tibiaServo3;

const int coxaPin1  = 8;
const int femurPin1 = 9;
const int tibiaPin1 = 10;

// const int coxaPin2  = 11;
// const int femurPin2 = 12;
// const int tibiaPin2 = 13;

// const int coxaPin3  = 9;
// const int femurPin3 = 10;
// const int tibiaPin3 = 11;

void setup() {
  Serial.begin(115200);

  coxaServo1.attach(coxaPin1);
  femurServo1.attach(femurPin1);
  tibiaServo1.attach(tibiaPin1);

  // coxaServo2.attach(coxaPin2);
  // femurServo2.attach(femurPin2);
  // tibiaServo2.attach(tibiaPin2);

  // coxaServo3.attach(coxaPin3);
  // femurServo3.attach(femurPin3);
  // tibiaServo3.attach(tibiaPin3);

  while (!Serial) {}
  while (Serial.available() > 0) {
    Serial.read();
  }

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    // Expecting format: coxa;femur;tibia  (e.g. "90;45;120")
    int firstSep  = cmd.indexOf(';');
    int secondSep = cmd.indexOf(';', firstSep + 1);

    if (firstSep == -1 || secondSep == -1) {
      // malformed line, ignore it
      return;
    }

    String coxaStr  = cmd.substring(0, firstSep);
    String femurStr = cmd.substring(firstSep + 1, secondSep);
    String tibiaStr = cmd.substring(secondSep + 1);
    digitalWrite(LED_BUILTIN, HIGH);
    int coxaVal  = constrain(coxaStr.toInt(), 0, 180);
    int femurVal = constrain(femurStr.toInt(), 0, 180);
    int tibiaVal = constrain(tibiaStr.toInt(), 0, 180);
    tibiaVal = map(tibiaVal, 0, 180, 180, 0);
 
    coxaServo1.write(coxaVal);
    femurServo1.write(femurVal);
    tibiaServo1.write(tibiaVal);

    // coxaServo2.write(coxaVal);
    // femurServo2.write(femurVal);
    // tibiaServo2.write(tibiaVal);
    
    digitalWrite(LED_BUILTIN, LOW);
  }
}

convert this code into pca code for the arduino mega