#include "LEDController.h"

void LEDController::Init(){
  for (int i = 0; i<sizeof(leds)/sizeof(leds[0]); i++){
    leds[i]->Init();
  }
}

void LEDController::TurnOn(int id){
  leds[id]->TurnOn();
}

void LEDController::TurnOff(int id){
  leds[id]->TurnOff();
}

boolean LEDController::IsOn(int id){
  return leds[id]->IsOn();
}

boolean LEDController::IsOff(int id){
  return leds[id]->IsOff();
}

