#ifndef HARDWARECONTROLLER_H
#define HARDWARECONTROLLER_H

#include <Arduino.h>
#include "LEDController.h"
#include "ButtonController.h"
#include "VibrationMotor.h"
#include "Screen.h"
#include "Clock.h"
#include "Bluetooth.h"

class HardwareController {
  private:
    LEDController *ledController;
    ButtonController *buttonController;
    VibrationMotor *vibrationMotor;
    Bluetooth *bluetooth;
    Clock clock;
    U8GLIB_SH1106_128X64 u8g;
    Screen displayScreen;
  public:
    HardwareController()
    : u8g(U8G_I2C_OPT_NO_ACK), displayScreen(&u8g) {
      ledController = new LEDController();
      buttonController = new ButtonController();
      vibrationMotor = new VibrationMotor(4, LOW);
      bluetooth = new Bluetooth();
    }

    /*
     * FUNCTION Init()
     *
     * Configures the hardware.
     *
     * @param (void)
     * @return (void)
     *
     */
    void Init();

    /*
     * FUNCTION TurnOnLED()
     *
     * Turns on the specified LED.
     *
     * @param (int id)
     * @return (void)
     *
     */
    void TurnOnLED(int id);
    
    /*
     * FUNCTION TurnOffLED()
     *
     * Turns off the specified LED.
     *
     * @param (int id)
     * @return (void)
     *
     */
    void TurnOffLED(int id);
    
    /*
     * FUNCTION IsLEDOn()
     *
     * Checks the state of the specified LED.
     *
     * @param (int id)
     * @return boolean : is LED on
     *
     */
    boolean IsLEDOn(int id);
    
    /*
     * FUNCTION IsLEDOff()
     *
     * Checks the state of the specified LED.
     *
     * @param (int id)
     * @return boolean : is LED off
     *
     */
    boolean IsLEDOff(int id);

    /*
     * FUNCTION IsButtonPressed()
     *
     * Checks if the specified button is pressed.
     *
     * @param (int id)
     * @return boolean : is button pressed
     *
     */
    boolean IsButtonPressed(int id);
    
    /*
     * FUNCTION TurnOnVibrationMotor()
     *
     * Turns on vibration motor.
     *
     * @param (void)
     * @return (void)
     *
     */
    void TurnOnVibrationMotor();
    
    /*
     * FUNCTION TurnOffVibrationMotor()
     *
     * Turns off vibration motor.
     *
     * @param (void)
     * @return (void)
     *
     */
    void TurnOffVibrationMotor();

    /*
     * FUNCTION GetTime()
     *
     * Returns the time as a string.
     *
     * @param (void)
     * @return String : time
     *
     */
    String GetTime();
    
    /*
     * FUNCTION GetDate()
     *
     * Returns the date as a string.
     *
     * @param (void)
     * @return String : date
     *
     */
    String GetDate();
    
    /*
     * FUNCTION GetTemperature()
     *
     * Returns the temperature as an int in Celsius.
     *
     * @param (void)
     * @return int : temperature in Celsius
     *
     */
    int GetTemperature();

    /*
     * FUNCTION SetFirstPage()
     *
     * Sets the first page for the screen.
     *
     * @param (void)
     * @return (void)
     *
     */
    void SetFirstPage();
    
    /*
     * FUNCTION HasNextPage()
     *
     * Checks whether the screen has a next page.
     *
     * @param (void)
     * @return (void)
     *
     */
    boolean HasNextPage();
    
    /*
     * FUNCTION DrawNotifications()
     *
     * Draws the notification number to the screen.
     *
     * @param (int numberOfNotifications)
     * @return (void)
     *
     */
    void DrawNotifications(int numberOfNotifications);

    /*
     * FUNCTION DrawTime()
     *
     * Draws the time to the screen.
     *
     * @param (void)
     * @return (void)
     *
     */
    void DrawTime();

    /*
     * FUNCTION DrawDate()
     *
     * Draws the date to the screen.
     *
     * @param (void)
     * @return (void)
     *
     */
    void DrawDate();
    
    /*
     * FUNCTION DrawTemperature()
     *
     * Draws the temperature to the screen.
     *
     * @param (void)
     * @return (void)
     *
     */
    void DrawTemperature();
    
    /*
     * FUNCTION SendData()
     *
     * Sends data to the connected bluetooth device.
     *
     * @param (String data)
     * @return (void)
     *
     */
    void SendData(String data);

    /*
     * FUNCTION GetData()
     *
     * Receives data from the bluetooth device.
     *
     * @param (void)
     * @return String : data
     *
     */
    String GetData();
};

#endif
