#ifndef MY_MOTOR_H
#define MY_MOTOR_H
#include <Arduino.h>

enum direction {
  CLOCKWISE,
  COUNTER_CLOCKWISE
};

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
    Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin);     // Instantiate a motor using two control pins and one speed pin (latter must be a PWM capable pin)
    direction getDirection();                                      // Returns one of the two enumarations (CLOCKWISE or COUNTER_CLOCKWISE) for current motor direction. 
    void setDirection(direction newDirection);                     // Sets current motor direction to one of the two enumarations (CLOCKWISE or COUNTER_CLOCKWISE)
    void On(byte SpeedVal);                                        // Turns on the motor by setting the motor speed (0-255)
    void Off();                                                    // Turns off the motor (same as setting motor speed to 0)
    byte currentSpeed();                                           // Returns the current motor speed (0-255)
};
#endif
