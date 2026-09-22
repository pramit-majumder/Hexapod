#include <Wire.h>

#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 150

#define SERVOMAX 600

void setServoAngle(uint8_t channel, int angle) {

  angle = constrain(angle, 0, 180);

  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);

  pwm.setPWM(channel, 0, pulse);

}

void setup() {
  Serial.begin(115200);

  Wire.begin();

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);

  pwm.setPWMFreq(50);

  delay(500);

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
 

    setServoAngle(0, coxaVal);
    setServoAngle(1, femurVal);
    setServoAngle(2, tibiaVal);

    setServoAngle(5, map(coxaVal, 0, 180, 180, 0));
    setServoAngle(4, femurVal);
    setServoAngle(3, constrain(tibiaVal + 20, 0, 180));

    setServoAngle(8, coxaVal);
    setServoAngle(7, femurVal);
    setServoAngle(6, tibiaVal);

    setServoAngle(9, coxaVal);
    setServoAngle(10, femurVal);
    setServoAngle(11, tibiaVal);
    
    digitalWrite(LED_BUILTIN, LOW);
  }
}

