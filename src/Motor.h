#ifndef MY_MOTOR_H
#define MY_MOTOR_H
#include <Arduino.h>

class Motor {
  // All local variables begin with underscore to differentiate them from other external variables   
  private:
    byte _motorPin1;
    byte _motorPin2; 
  	byte _motorSpeedPin; 
    byte _speedValue; 
    bool _currentDirCW;
	
  public:
    Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin);
    void init();
    void DirCW();
    void DirCCW();
    void On(byte SpeedVal);
	void Off();
    bool IsDirCW();
	bool IsDirCCW();
    byte CurrentSpeed();
};
#endif
