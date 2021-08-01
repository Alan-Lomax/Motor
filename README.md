# Motor
Motor Shield Class

This class implements the commands to control a DC motor using a small shield hooked up to your arduino.
It is defined as follows:
  
      Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin);
	  
Where typical of most motor shields there are two pins to enable motor direction and one PWM pin to handle the motor speed.
The shield manages the details of which branches of the H bridge are on at any moment in time.

Setting and Getting the motor direction uses an enumeration with two possible values CLOCKWISE or COUNTER_CLOCKWISE
as can be seen in the sample code below.

  
### Files: Motor.h, Motor.CPP

### Example

The following code waits for a button (push and release) and then ramps the motor spped from zero to full speed.
A second button push and release ramps the motor speed down to zero at a different rate.

     #include "Motor.h"
    /*
      Simple Motor Control using a L298N Motor Control Board

      Notes
      The motor speed ramps to target, it does not jump to target.
    */
    #define    BUTTON_PIN 2                                            // use a pushbutton between this pin and ground to start the motor.
    /*
      The L298N Motor board supports up to two motors. (This code is using only one half of the boards capability)
      Each motor needs two pins for power control and one pin to set the speed (via PWM). See pin defintions below.
    */
    #define     MotorPin1 7
    #define     MotorPin2 8
    #define MotorSpeedPin 9

    int motorValue;                                                    // To store the actual instantaneous commanded speed of the motor
    Motor motor1(MotorPin1, MotorPin2, MotorSpeedPin);                 // define motor1 as our new member of the Motor class

    void setup() {
      Serial.begin(9600);                                              // for serial / debug console
      Serial.println(__FILE__);                                        // by default I like to output the file name as a minimum.

      pinMode(BUTTON_PIN, INPUT_PULLUP);                               // Button pin is defined as an input
      pinMode(LED_BUILTIN, OUTPUT);                                    // LED pin is defined as an output

      motor1.setDirection(CLOCKWISE);                                  // set the direction of rotation using the enum CLOCKWISE or COUNTERCLOCKWISE
    }

    void loop() {
      wait ();                                                         // wait for a complete press and release of our button

      digitalWrite(LED_BUILTIN, true);                                 // turn on LED to ack that button press has been read in
      for ( motorValue = 0; motorValue <= 254; motorValue += 1 ) {     // ramp speed up from zero to near full speed
        motor1.On(motorValue);
        delay(30);                                                     // 30 milliseconds between each increment of the motor speed.
      }

      digitalWrite(LED_BUILTIN, false);                                 // turn off LED to ack ramp is complete
      Serial.print("Current Speed is : ");
      Serial.println(motor1.currentSpeed());

      wait ();
      digitalWrite(LED_BUILTIN, true);                                 // turn on LED to ack that button press has been read in
      for ( motorValue = 254; motorValue > 0; motorValue -= 1 ) {      // ramp speed down to zero from full speed
        motor1.On(motorValue);
        delay(50);                                                     // This time 50 milliseconds between each reduction of the motor speed (notice the effect).
      }
      digitalWrite(LED_BUILTIN, false);                                // turn off LED to ack ramp is complete
      Serial.print("Current Speed is : ");
      Serial.println(motor1.currentSpeed());
    }

    void wait () {
      while (digitalRead(BUTTON_PIN) == true) {};                      // Wait here for the button to be pressed. (input is using a pullup, and button press grounds it)
      while (digitalRead(BUTTON_PIN) == false) {};                     // Wait here for the button to be let go.  (after letting go the pullup will make it read high again)
    }

### Instantiation
    Motor(byte MotorPin1, byte MotorPin2, byte MotorSpeedPin);     // Instantiate a motor using two control pins and one speed pin (latter must be a PWM capable pin)

### Methods
    void On(byte SpeedVal);                                        // Turns on the motor by setting the motor speed (0-255)
    void Off();                                                    // Turns off the motor (same as setting motor speed to 0)


### Properties:
    direction getDirection();                                      // Returns one of the two enumarations (CLOCKWISE or COUNTER_CLOCKWISE) for current motor direction. 
    void setDirection(direction newDirection);                     // Sets current motor direction to one of the two enumarations (CLOCKWISE or COUNTER_CLOCKWISE)
    byte currentSpeed();                                           // Returns the current motor speed (0-255)


