#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

#define ECHO_ENABLED 1   // 1 = Arduino echoes what it executed, 0 = silent (use 0 for walking)

Servo servo2;
Servo servo3;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 150
#define SERVOMAX 600

// {coxa, femur, tibia} PCA9685 channels for legs 1-5.
// Leg 6 is handled separately: coxa on PCA channel 15, femur on pin 8, tibia on pin 7.
const uint8_t LEG_CH[5][3] = {
  {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}, {12, 13, 14}
};

void setServoAngle(uint8_t channel, int angle) {
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}

void moveLeg(int leg, int coxa, int femur, int tibia) {
  coxa  = constrain(coxa, 0, 180);
  femur = constrain(femur, 0, 180);
  tibia = constrain(tibia, 0, 180);

#if ECHO_ENABLED
  // Echo the clamped values, before the tibia inversion
  Serial.print("OK ");
  Serial.print(leg);   Serial.print(';');
  Serial.print(coxa);  Serial.print(';');
  Serial.print(femur); Serial.print(';');
  Serial.println(tibia);
#endif

  tibia = map(tibia, 0, 180, 180, 0);  // existing tibia inversion

  if (leg >= 1 && leg <= 5) {
    const uint8_t* ch = LEG_CH[leg - 1];
    setServoAngle(ch[0], coxa);
    setServoAngle(ch[1], femur);
    setServoAngle(ch[2], tibia);
  } else if (leg == 6) {
    setServoAngle(15, coxa);
    servo2.write(femur);
    servo3.write(tibia);
  } else {
#if ECHO_ENABLED
    Serial.print("ERR bad leg ");
    Serial.println(leg);
#endif
  }
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(5);  // don't block ~1 s on a partial line
  Wire.begin();
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
  delay(500);
  while (!Serial) {}
  while (Serial.available() > 0) Serial.read();

  servo2.attach(8);
  servo3.attach(7);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.length() == 0) return;

    // Expected format: leg;coxa;femur;tibia  (e.g. "1;90;45;120")
    int s1 = cmd.indexOf(';');
    int s2 = cmd.indexOf(';', s1 + 1);
    int s3 = cmd.indexOf(';', s2 + 1);
    if (s1 == -1 || s2 == -1 || s3 == -1) {
#if ECHO_ENABLED
      Serial.print("ERR ");
      Serial.println(cmd);
#endif
      return;
    }

    int leg   = cmd.substring(0, s1).toInt();
    int coxa  = cmd.substring(s1 + 1, s2).toInt();
    int femur = cmd.substring(s2 + 1, s3).toInt();
    int tibia = cmd.substring(s3 + 1).toInt();

    moveLeg(leg, coxa, femur, tibia);
  }
}