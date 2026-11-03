#include <ServoEasing.hpp>

constexpr uint8_t SERVO_PIN = 3;  // P0.03 (P1-2)
constexpr int START_ANGLE_DEG = 90;
constexpr int MIN_ANGLE_DEG = 20;
constexpr int MAX_ANGLE_DEG = 135;
constexpr uint16_t ONE_WAY_MOVE_MS = 1750;
constexpr uint16_t END_HOLD_MS = 100;
constexpr uint16_t EASING_UPDATE_MS = 20;
constexpr int MIN_PULSE_US = 1000;
constexpr int MAX_PULSE_US = 2000;

ServoEasing wingServo;
int targetAngleDeg = MIN_ANGLE_DEG;
bool isMoving = true;
uint32_t holdStartMs = 0;
uint32_t lastUpdateMs = 0;

void setup() {
  wingServo.attach(SERVO_PIN, START_ANGLE_DEG, MIN_PULSE_US, MAX_PULSE_US);
  wingServo.setEasingType(EASE_SINE_IN_OUT);

  // The first 90 -> 45 degree move is half the normal travel distance.
  wingServo.startEaseToD(targetAngleDeg, ONE_WAY_MOVE_MS / 2,
                         DO_NOT_START_UPDATE_BY_INTERRUPT);
  lastUpdateMs = millis();
}

void loop() {
  if (isMoving) {
    const uint32_t now = millis();
    if (now - lastUpdateMs < EASING_UPDATE_MS) {
      return;
    }
    lastUpdateMs = now;

    if (wingServo.update()) {
      isMoving = false;
      holdStartMs = now;
    }
    return;
  }

  if (millis() - holdStartMs >= END_HOLD_MS) {
    targetAngleDeg =
        (targetAngleDeg == MIN_ANGLE_DEG) ? MAX_ANGLE_DEG : MIN_ANGLE_DEG;
    wingServo.startEaseToD(targetAngleDeg, ONE_WAY_MOVE_MS,
                           DO_NOT_START_UPDATE_BY_INTERRUPT);
    lastUpdateMs = millis();
    isMoving = true;
  }
}
