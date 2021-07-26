#include "Motor.h"
Motor::Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin){
  // Save the passed pins into the local variables
  _motorPin1     = MotorPin1;
  _motorPin2     = MotorPin2; 
  _motorSpeedPin = MotorSpeedPin; 
  init();
}
void Motor::init() {
  pinMode(_motorPin1, OUTPUT);
  pinMode(_motorPin2, OUTPUT);
  pinMode(_motorSpeedPin, OUTPUT);
  // Trying to avoid duplicate code.
  // call the existing function off() to turn everything off
  Off();
}
// Methods
void Motor::DirCW() {
  digitalWrite(_motorPin1, HIGH);
  digitalWrite(_motorPin2, LOW);
  _currentDirCW = true;
}
void Motor::DirCCW() {
  digitalWrite(_motorPin1, LOW);
  digitalWrite(_motorPin2, HIGH);
  _currentDirCW = false;
}
void Motor::On(byte SpeedVal) {         // turn on motor at speed of the passed value
  _speedValue = SpeedVal;
  analogWrite(_motorSpeedPin, _speedValue);
}
void Motor::Off() {                  // set speed to zero
  _speedValue = 0;
  analogWrite(_motorSpeedPin, _speedValue);
}
// Properties (returns a value)
bool Motor::IsDirCW() {              // returns true if current direction is CW, False otherwise.
   return _currentDirCW;
}
bool Motor::IsDirCCW() {             // This will always be the opposite of IsDirCW()
   return !IsDirCW();
}
byte Motor::CurrentSpeed() {         // returns the current speed value ( 0 - 255)
   return _speedValue;
}
