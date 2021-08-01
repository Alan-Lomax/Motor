#include "Motor.h"
#include "direction.h"

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
  // To avoid duplicate code just call the existing function off() to turn everything off
  Off();
}

// Methods
void Motor::NewDirection(direction _Direction){
  digitalWrite(_motorPin1, LOW);        // Before changing direction 
  digitalWrite(_motorPin2, LOW);        // ensure all legs of thge H bridge are off
  switch (_Direction) {
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

void Motor::Off() {                  // set speed to zero by calling the on function with a value of zero
  On(0);                             // Again this approach just minimizes duplication of lines of code.
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
