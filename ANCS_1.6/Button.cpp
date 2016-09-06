#include "Button.h"

/*
 * FUNCTION Init()
 *
 * Configures the hardware.
 *
 * @param (void)
 * @return (void)
 *
 */
void Button::Init() {
  pinMode(pin, INPUT_PULLUP);           // set pin to input
  digitalWrite(pin, buttonState);
}

/*
 * FUNCTION IsPressed()
 *
 * Checks whether the button is pressed.
 *
 * @param (void)
 * @return boolean : is button pressed
 *
 */
boolean Button::IsPressed() {
  //sample the state of the button - is it pressed or not?
  buttonState = digitalRead(pin);
 
  //filter out any noise by setting a time buffer
  if ( (millis() - lastDebounceTime) > debounceDelay) {
 
    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"
    if ( (buttonState == LOW) && (outputState == 0) ) {
      outputState = 1; //now the LED is on, we need to change the state
      lastDebounceTime = millis(); //set the current time
      return true;
    }
    else if ( (buttonState == LOW) && (outputState == 1) ) {
      outputState = 0; //now the LED is off, we need to change the state
      lastDebounceTime = millis(); //set the current time
      return false;
    }//close if/else
 
  }//close if(time buffer)
  return false;  
}

