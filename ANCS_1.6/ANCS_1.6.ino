#include <SoftwareSerial.h>
#include "U8glib.h"
#include <DS3231.h>
#include <Wire.h>
#include "Controller.h"

Controller controller;

/*
 * FUNCTION setup()
 * 
 * Configures all of the states of the hardware
 * 
 * @param (void)
 * @return (void)
 * 
 */ 
void setup()
{
  // Setup watch
  controller.Setup();
}

/*
 * FUNCTION Loop()
 * 
 * Makes appropriate function calls each time it is called
 * by the arduino 
 * 
 * @param (void)
 * @return (void)
 * 
 */ 
void loop() 
{
  controller.CheckButtons();  
  controller.DrawScreen();
  controller.BluetoothCommunications(); 
}
