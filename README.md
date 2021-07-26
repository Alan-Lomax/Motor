# Motor
Motor Shield Class

This class implements the commands to control a DC motor using a small shield hooked up to your arduino.
It is defined as follows:
  
      Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin);
	  
Where typical of most motor shields there are two pins to enable motor direction and one PWM pin to handle the motor speed.
The shield manages the details of which branches of the H bridge are on at any moment in time.  
  
### Files: Motor.h, Motor.CPP

### Usage:
Include the header file near the top of your code. (After this is done the compiler will know how to handle you using it.)

    #include "Motor.h";

### Instantiation:

This is one example of how to define your pins and the create a member of the motor class.

     const byte   Mtr1Pin    = 7;  // One of the Motor Pins
     const byte   Mtr2Pin    = 8;  // Second of the Motor Pins
     const byte   MtrSpdPin  = 9;  // This pin has PWM for speed control of the Motor
     Motor  motor1     (Mtr1Pin, Mtr2Pin, MtrSpdPin);

### Methods
    void DirCW();                // Set direction to Clockwise (check on first use - may need to reverse motor leads)
    void DirCCW();               // Set direction to Counter Clockwise
    void On(byte SpeedVal);      // Set speed to SpeedVal   ( Range = 0-255)
	void Off();                  // Turn Off the motor

### Properties:
    bool IsDirCW();              // Returns true if direction is clockwise
	bool IsDirCCW();             // Returns true if direction is counter clockwise
    byte CurrentSpeed();         // Returns the current speed (0-255)
	


