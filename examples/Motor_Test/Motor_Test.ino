#include <Motor.h>
/*
  Simple Motor Control - all Testing done using a L298N Motor Control Board
  Also 

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
}

void loop() {
  wait ();                                                         // wait for a complete press and release of our button

  digitalWrite(LED_BUILTIN, true);                                 // turn on LED to ack that button press has been read in
  setDirection(CLOCKWISE);                                         // set the direction of rotation using the enum CLOCKWISE or COUNTERCLOCKWISE
  for ( motorValue = 0; motorValue <= 254; motorValue += 1 ) {     // ramp speed up from zero to near full speed
    motor1.on(motorValue);
    delay(30);                                                     // 30 milliseconds between each increment of the motor speed.
  }
  
  digitalWrite(LED_BUILTIN, false);                                 // turn off LED to ack ramp is complete
  Serial.print("Current Speed is : ");
  Serial.println(motor1.CurrentSpeed());

  wait ();
  digitalWrite(LED_BUILTIN, true);                                 // turn on LED to ack that button press has been read in
  motor1.DirCW();
  for ( motorValue = 254; motorValue > 0; motorValue -= 1 ) {      // ramp speed down to zero from full speed
    motor1.on(motorValue);
    delay(50);                                                     // This time 50 milliseconds between each reduction of the motor speed (notice the effect).
  }
  digitalWrite(LED_BUILTIN, false);                                // turn off LED to ack ramp is complete
  Serial.print("Current Speed is : ");
  Serial.println(motor1.CurrentSpeed());
}

void wait () {
  while (digitalRead(BUTTON_PIN) == true) {};                      // Wait here for the button to be pressed. (input is using a pullup, and button press grounds it)
  while (digitalRead(BUTTON_PIN) == false) {};                     // Wait here for the button to be let go.  (after letting go the pullup will make it read high again)
}