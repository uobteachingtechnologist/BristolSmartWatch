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
    const int buttonstate = 8; // Other button pin
    const int sleepwake = 6; // Sleep wake button pin
    const int tiltscreen = 5; // Tilt sensor pin
    const int led = 9; // LED pin
    const int vibrate = 4; // Vibration motor pin
  
    int screen = 0;
    int screensleep = 0;
    Clock clock; // Decleration for RTC
    int number; // Number of notifications on phone

    unsigned long previousMillis = 0; // Stores last time watch was updated
    const long interval = 1000; // interval at which to check for watch updates (milliseconds)

    U8GLIB_SH1106_128X64 u8g; 

    Screen displayScreen;
    
    SoftwareSerial mySerial; // RX, TX
    
    BluetoothCommunication bluetoothCommunication; 

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
  public:
    Controller()
    // Using initialiser list to initialise the objects.
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
    * FUNCTION Loop()
    * 
    * Performs check for button state updates, screen updates
    * and checks for bluetooth communication.
    * 
    * @param (void)
    * @return (void)
    * 
    */
    void Loop();
};
#endif
