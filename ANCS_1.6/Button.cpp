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
  digitalWrite(pin, defaultValue);
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
  int currentState = digitalRead(pin);
  if (currentState != previousState) {
    previousState = currentState;
    if (currentState != defaultValue) {
      return true;
    }
  }
  return false;
}

