#ifndef WATCH_H
#define WATCH_H

#include "Clock.h"
#include "BluetoothCommunication.h"
#include "Screen.h"

/*
 *  CLASS Controller
 *  
 *  Class used to control the watch
 *  and associated functions.
 */
class Watch {
  private:
    // Pin numbers
    const int arduinoLED = 17;
    const int button1 = 8;
    const int button2 = 6;
    const int tiltscreen = 5;
    const int externalLED = 9;
    const int vibrate = 4;
  
    boolean isExternalLEDOn = false;
    boolean isScreenOff = false;
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
    * FUNCTION CheckLEDButton()
    * 
    * Checks the state of the LED button and updates the external LED state.     
    * 
    * @param (void)     
    * @return (void)
    * 
    */
    void CheckLEDButton();

   /*
    * FUNCTION UpdateExternalLEDState()
    * 
    * Updates the external LED state.     
    * 
    * @param (void)     
    * @return (void)
    * 
    */
    void UpdateExternalLEDState();

   /*
    * FUNCTION CheckScreenOffButton()
    * 
    * Checks the state of the screen off button and updates the screen power state.
    * 
    * @param (void)
    * @param (void)
    * 
    */
    void CheckScreenOffButton();

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
    Watch()
    // Using initialiser list to initialise the objects.
    : mySerial(10, 16),
      bluetoothCommunication(&mySerial),
      u8g(U8G_I2C_OPT_NO_ACK),
      displayScreen(&u8g)
    {};

   /*
    * FUNCTION HardwareInit()
    * 
    * Performs initial setup of Arduino hardware.
    * 
    * @param (void)
    * @return (void)
    * 
    */
    void HardwareInit();

   /*
    * FUNCTION Update()
    * 
    * Performs check for button state updates, screen updates
    * and checks for bluetooth communication.
    * 
    * @param (void)
    * @return (void)
    * 
    */
    void Update();
};
#endif
