#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Clock.h"
#include "BluetoothCommunication.h"
#include "Screen.h"

/*
 *  CLASS Controller
 *  
 *  Class used to control the watch
 *  and associated functions.
 */
class Controller {
  private:
    const int arduinoLED = 17;
  
    int screen = 0;
    int screensleep = 0;
    int buttonstate = 8; // Other button pin
    int sleepwake = 6; // Sleep wake button pin
    int tiltscreen = 5; // Tilt sensor pin
    int led = 9; // LED pin
    Clock clock; // Decleration for RTC
    int vibrate = 4; // Vibration motor pin
    int number; // Number of notifications on phone

    U8GLIB_SH1106_128X64 u8g; 

    Screen displayScreen;
    
    SoftwareSerial mySerial; // RX, TX
    
    BluetoothCommunication bluetoothCommunication; 
  public:
    Controller()
    // Using initialiser lists to initialise the objects.
    : mySerial(10, 16),
      bluetoothCommunication(&mySerial),
      u8g(U8G_I2C_OPT_NO_ACK),
      displayScreen(&u8g)
    {};

   /*
    * FUNCTION Setup()
    * 
    * Performs initial setup of Arduino hardware.
    * 
    * @param (void)
    * @return (void)
    * 
    */
    void Setup();

   /*
    * FUNCTION CheckButtons()
    * 
    * Checks the states of all the hardware buttons.
    * 
    * @param (void)
    * @return (void)
    * 
    */
    void CheckButtons();

   /*
    * FUNCTION DrawScreen()
    * 
    * Calls all of the appropriate methods to draw all information      * to the screen
    * 
    * @param (void)
    * @return (void)
    * 
    */
    void DrawScreen();

   /*
    * FUNCTION BluetoothCommuncations()
    * 
    * Calls BluetoothCommuncation.Read() to read any information
    * over Bluetooth. Writes a notification to the screen if 
    * there is a new notifcation and also vibrates.
    * 
    * @param (void)
    * @return (void)
    * 
    */
    void BluetoothCommunications();
};
#endif
