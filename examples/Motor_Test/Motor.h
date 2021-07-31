#ifndef MY_MOTOR_H
#define MY_MOTOR_H
#include <Arduino.h>

enum direction {CLOCKWISE, COUNTERCLOCKWISE};

class Motor {
    // All local variables begin with underscore to differentiate them from other external variables
  private:
    byte _motorPin1;
    byte _motorPin2;
    byte _motorSpeedPin;
    byte _speedValue;
    bool _currentDirCW;
    void init();

  public:
    Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin);
    void      setDirection(direction whichWay);
    direction getDirection();
    void      On(byte SpeedVal);
    void      Off();
    byte      currentSpeed();
};
#endif
