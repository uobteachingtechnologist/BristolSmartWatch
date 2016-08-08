#include "HardwareController.h"

void HardwareController::Init(){
  ledController->Init();
  buttonController->Init();
  vibrationMotor->Init();
  bluetooth->Init();
}

void HardwareController::TurnOnLED(int id){
  ledController->TurnOn(id);
}

void HardwareController::TurnOffLED(int id){
  ledController->TurnOff(id);
}

boolean HardwareController::IsLEDOn(int id){
  return ledController->IsOn(id);
}

boolean HardwareController::IsLEDOff(int id){
  return ledController->IsOff(id);
}

boolean HardwareController::IsButtonPressed(int id){
  return buttonController->IsButtonPressed(id);
}

void HardwareController::TurnOnVibrationMotor(){
  vibrationMotor->TurnOn();
}

void HardwareController::TurnOffVibrationMotor(){
  vibrationMotor->TurnOff();
}

String HardwareController::GetTime() {
  return clock.GetTime();
}

String HardwareController::GetDate() {
  return clock.GetDate();
}

int HardwareController::GetTemperature() {
  return clock.GetTemperature();
}

void HardwareController::SetFirstPage(){
  u8g.firstPage();
}

boolean HardwareController::HasNextPage(){
  return u8g.nextPage();
}

void HardwareController::DrawNotifications(int numberOfNotifications){
  displayScreen.DrawNotifications(numberOfNotifications);
}

void HardwareController::DrawTime(){
  displayScreen.DrawTime(clock.GetTime());
}

void HardwareController::DrawDate(){
  displayScreen.DrawDate(clock.GetDate());  
}

void HardwareController::DrawTemperature(){
  displayScreen.DrawTemperature(clock.GetTemperature());
}  

void HardwareController::SendData(String data){
  char *dataCharArray = &data[0];
  bluetooth->SendData(dataCharArray);
}

String HardwareController::GetData(){
  return bluetooth->GetData();
}

