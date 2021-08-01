#include "Motor.h"
Motor::Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin) {
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
  Off();                                // To avoid duplicate code just call the existing function off()
}

// Methods
void Motor::setDirection(direction newDirection){
  digitalWrite(_motorPin1, LOW);        // Before changing direction 
  digitalWrite(_motorPin2, LOW);        // ensure all legs of thge H bridge are off
  switch (newDirection) {
    case CLOCKWISE:
      digitalWrite(_motorPin1, HIGH);
      _currentDirCW = true;
      break;
    case COUNTER_CLOCKWISE:
      digitalWrite(_motorPin2, HIGH);
      _currentDirCW = false;
      break;
  }
}

void Motor::On(byte SpeedVal) {         // turn on motor at speed of the passed value
  _speedValue = SpeedVal;
  analogWrite(_motorSpeedPin, _speedValue);
}

void Motor::Off() {                  // Just set speed to zero
  On(0);                             // This approach just minimizes duplication of lines of code.
}

// Properties (returns a value)
direction Motor::getDirection() {
  if ( _currentDirCW) {
    return CLOCKWISE;
  }
  else {
    return COUNTER_CLOCKWISE;
  }
}

byte Motor::currentSpeed() {         // returns the current speed value ( 0 - 255)
  return _speedValue;
}
