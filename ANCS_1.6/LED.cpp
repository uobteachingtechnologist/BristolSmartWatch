#include "LED.h"

/*
 * FUNCTION Init()
 *
 * Configures the hardware.
 *
 * @param (void)
 * @return (void)
 *
 */
void LED::Init(){
  pinMode(pin, OUTPUT);           // set pin to input
  digitalWrite(pin, defaultValue);
}

/*
 * FUNCTION TurnOn()
 *
 * Turns on the LED.
 *
 * @param (void)
 * @return (void)
 *
 */
void LED::TurnOn(){
  digitalWrite(pin, !defaultValue);
  currentState = !defaultValue;
}

/*
 * FUNCTION TurnOff()
 *
 * Turns off the LED.
 *
 * @param (void)
 * @return (void)
 *
 */
void LED::TurnOff(){
  digitalWrite(pin, defaultValue);
  currentState = defaultValue;
}

/*
 * FUNCTION IsOn()
 *
 * Checks if the LED is on.
 *
 * @param (void)
 * @return boolean : is LED on
 *
 */
boolean LED::IsOn(){
  if (currentState==defaultValue)
    return false;
  return true;
}

/*
 * FUNCTION IsOff()
 *
 * Checks if the LED is off.
 *
 * @param (void)
 * @return boolean : is LED off
 *
 */
boolean LED::IsOff(){
  if (currentState==defaultValue)
    return true;
  return false;
}

