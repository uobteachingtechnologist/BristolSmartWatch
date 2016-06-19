#ifndef LED_H
#define LED_H
#include <Arduino.h>

class LED {
  private:
    int pin;
    int defaultValue;
    int currentState;
  public:
    LED(int pin, int defaultValue) {
      this->pin = pin;
      this->defaultValue = defaultValue;
      this->currentState = defaultValue;
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
     * FUNCTION TurnOn()
     *
     * Turns on the LED.
     *
     * @param (void)
     * @return (void)
     *
     */
    void TurnOn();
    
    /*
     * FUNCTION TurnOff()
     *
     * Turns off the LED.
     *
     * @param (void)
     * @return (void)
     *
     */
    void TurnOff();
    
    /*
     * FUNCTION IsOn()
     *
     * Checks if the LED is on.
     *
     * @param (void)
     * @return boolean : is LED on
     *
     */
    boolean IsOn();
    /*
     * FUNCTION IsOff()
     *
     * Checks if the LED is off.
     *
     * @param (void)
     * @return boolean : is LED off
     *
     */
    boolean IsOff();
};

#endif
