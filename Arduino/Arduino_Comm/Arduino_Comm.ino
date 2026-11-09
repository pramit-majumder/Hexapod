#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define ECHO_ENABLED 1   // 1 = echo executed commands, 0 = silent (use 0 for walking)

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

#define SERVOMIN 150
#define SERVOMAX 600

// {board (1 or 2), coxa, femur, tibia} for legs 1-6
const uint8_t LEG_CH[6][4] = {
  {2, 13, 14, 15},  // leg 1
  {2,  9,  8,  7},  // leg 2
  {2,  2,  1,  0},  // leg 3
  {1,  2,  1,  0},  // leg 4
  {1,  4,  6,  5},  // leg 5
  {1, 13, 14, 15}   // leg 6
};

void setServoAngle(Adafruit_PWMServoDriver &pwm, uint8_t channel, int angle) {
  angle = constrain(angle, 0, 180);
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}

void moveLeg(int leg, int coxa, int femur, int tibia) {
  if (leg < 1 || leg > 6) {
#if ECHO_ENABLED
    Serial.print("ERR bad leg ");
    Serial.println(leg);
#endif
    return;
  }

  coxa  = constrain(coxa, 0, 180);
  femur = constrain(femur, 0, 180);
  tibia = constrain(tibia, 0, 180);

#if ECHO_ENABLED
  Serial.print("OK ");
  Serial.print(leg);   Serial.print(';');
  Serial.print(coxa);  Serial.print(';');
  Serial.print(femur); Serial.print(';');
  Serial.println(tibia);
#endif

  tibia = 180 - tibia;  // existing tibia inversion

  const uint8_t* ch = LEG_CH[leg - 1];
  Adafruit_PWMServoDriver &pwm = (ch[0] == 1) ? pwm1 : pwm2;
  setServoAngle(pwm, ch[1], coxa);
  setServoAngle(pwm, ch[2], femur);
  setServoAngle(pwm, ch[3], tibia);
}

// Parses "leg;coxa;femur;tibia". Returns false if malformed.
bool parseCommand(char* s, int &leg, int &coxa, int &femur, int &tibia) {
  int vals[4];
  for (int i = 0; i < 4; i++) {
    char* end;
    long v = strtol(s, &end, 10);
    if (end == s) return false;                 // no digits
    vals[i] = (int)v;
    if (i < 3) {
      if (*end != ';') return false;
      s = end + 1;
    } else if (*end != '\0') {
      return false;                             // trailing junk
    }
  }
  leg = vals[0]; coxa = vals[1]; femur = vals[2]; tibia = vals[3];
  return true;
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000);

  pwm1.begin();
  pwm2.begin();
  pwm1.setOscillatorFrequency(27000000);
  pwm2.setOscillatorFrequency(27000000);
  pwm1.setPWMFreq(50);
  pwm2.setPWMFreq(50);

  pinMode(LED_BUILTIN, OUTPUT);

  // Blink 3x if either PCA9685 doesn't respond on I2C
  Wire.beginTransmission(0x40); bool ok1 = (Wire.endTransmission() == 0);
  Wire.beginTransmission(0x41); bool ok2 = (Wire.endTransmission() == 0);
  if (!ok1 || !ok2) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED_BUILTIN, HIGH); delay(200);
      digitalWrite(LED_BUILTIN, LOW);  delay(200);
    }
  }

  unsigned long t0 = millis();
  while (!Serial && millis() - t0 < 2000) {}
  delay(500);
  while (Serial.available() > 0) Serial.read();
}

void loop() {
  static char buf[48];
  static uint8_t len = 0;

  while (Serial.available() > 0) {
    char c = (char)Serial.read();

    if (c == '\r') continue;

    if (c == '\n') {
      buf[len] = '\0';
      if (len > 0) {
        int leg, coxa, femur, tibia;
        if (parseCommand(buf, leg, coxa, femur, tibia)) {
          moveLeg(leg, coxa, femur, tibia);
        } else {
#if ECHO_ENABLED
          Serial.print("ERR ");
          Serial.println(buf);
#endif
        }
      }
      len = 0;
    } else if (len < sizeof(buf) - 1) {
      buf[len++] = c;
    } else {
      len = 0;  // overlong line: discard
    }
  }
}