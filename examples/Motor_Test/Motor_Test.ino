#include <Button.h>
#include <Led.h>
#include <Motor.h>
/*
  Simple Motor Control - all Testing done using a L298N Motor Control Board
  Also motor speed ramps to target, does not jmp to target.

  Note that the L298N Motor board supports up to two motors. (This code is using only one half of the boards capability)
  Each motor has two pins for power control and one pin to set the speed (via PWM)

*/
#define DEBUG true

#define    BUTTON_PIN 2
#define     MotorPin1 7
#define     MotorPin2 8
#define MotorSpeedPin 9

pinmode(BUTTON_PIN, input_pullup);
pinmode(LED_BUILTIN, output);

Motor motor1(MotorPin1, MotorPin2, MotorSpeedPin);

int motorValue = 0;   // Actual instantaneous commanded speed of the motor (when ramping to target speed)

void setup() {
    Serial.begin(9600);
    Serial.println(__FILE__);
}

// test of all 3 object classes.

void loop() {
  while (button1.IsNotPressed()) {};    // Wait here for the button to be pressed.
  while (button1.IsPressed()) {};       // Then wait here for it to be released before continuing.

  digitalWrite(LED_BUILTIN,true);                                  // turn on LED to ack that button press has been read in
  motor1.DirCW();
  for ( motorValue = 0; motorValue <= 254; motorValue += 1 ) {     // ramp speed up from zero to near full speed
    motor1.On(motorValue);
    delay(30);
  }
  digitalWrite(LED_BUILTIN,false);                                  // turn off LED to ack ramp is complete
    Serial.print("Current Speed is : ");
    Serial.println(motor1.CurrentSpeed());
    
    
      while (button1.IsNotPressed()) {};    // Wait here for the button to be pressed.
  while (button1.IsPressed()) {};       // Then wait here for it to be released before continuing.

  digitalWrite(LED_BUILTIN,true);                                  // turn on LED to ack that button press has been read in
  motor1.DirCW();
  for ( motorValue = 254; motorValue > 0; motorValue -= 1 ) {     // ramp speed down to zero from full speed
    motor1.On(motorValue);
    delay(30);
  }
  digitalWrite(LED_BUILTIN,false);                                      // turn off LED to ack ramp is complete
    Serial.print("Current Speed is : ");
    Serial.println(motor1.CurrentSpeed());
}
