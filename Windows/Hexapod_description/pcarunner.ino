#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

#define SERVOMIN 150
#define SERVOMAX 600

void setServoAngle(Adafruit_PWMServoDriver &pwm,
                   uint8_t channel, int angle) {
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}

void setup() {
  Wire.begin();

  pwm1.begin();
  pwm2.begin();

  pwm1.setOscillatorFrequency(27000000);
  pwm2.setOscillatorFrequency(27000000);

  pwm1.setPWMFreq(50);
  pwm2.setPWMFreq(50);

  delay(500);
}

void loop() {
  // PCA #1: channels 0–8
  setServoAngle(pwm1, 13, 90);
  setServoAngle(pwm1, 14, 90);
  setServoAngle(pwm1, 15, 90);

  setServoAngle(pwm1, 6, 90);
  setServoAngle(pwm1, 7, 90);
  setServoAngle(pwm1, 5, 90);

  setServoAngle(pwm1, 2, 90);
  setServoAngle(pwm1, 1, 90);
  setServoAngle(pwm1, 0, 90);

  // PCA #2: channels 0–8
  setServoAngle(pwm2, 2, 90);
  setServoAngle(pwm2, 1, 90);
  setServoAngle(pwm2, 0, 90);

  setServoAngle(pwm2, 7, 90);
  setServoAngle(pwm2, 8, 90);
  setServoAngle(pwm2, 9, 90);

  setServoAngle(pwm2, 13, 90);
  setServoAngle(pwm2, 14, 90);
  setServoAngle(pwm2, 15, 90);

  delay(1000);
}