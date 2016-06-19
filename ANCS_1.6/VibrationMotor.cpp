#include "VibrationMotor.h"

void VibrationMotor::Init(){
  pinMode(pin, OUTPUT);           // set pin to input
  digitalWrite(pin, defaultValue);
}

void VibrationMotor::TurnOn(){
  digitalWrite(pin, !defaultValue);
  currentState = !defaultValue;
}

void VibrationMotor::TurnOff(){
  digitalWrite(pin, defaultValue);
  currentState = defaultValue;
}

boolean VibrationMotor::IsOn(){
  if (currentState==defaultValue)
    return false;
  return true;
}

boolean VibrationMotor::IsOff(){
  if (currentState==defaultValue)
    return true;
  return false;
}

