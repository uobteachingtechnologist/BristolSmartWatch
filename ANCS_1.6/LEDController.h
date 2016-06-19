#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#include <Arduino.h>
#include "LED.h"

class LEDController {
  private:
    LED *leds[2];
  public:
    LEDController() {
      leds[0] = new LED(17, LOW);
      leds[1] = new LED(9, LOW);
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
     * Turns on the specified LED.
     *
     * @param (int id)
     * @return (void)
     *
     */
    void TurnOn(int id);
    
    /*
     * FUNCTION TurnOff()
     *
     * Turns off the specified LED.
     *
     * @param (int id)
     * @return (void)
     *
     */
    void TurnOff(int id);
    
    /*
     * FUNCTION IsOn()
     *
     * Checks the state of the specified LED.
     *
     * @param (int id)
     * @return boolean : is LED on
     *
     */
    boolean IsOn(int id);
    
    /*
     * FUNCTION IsOff()
     *
     * Checks the state of the specified LED.
     *
     * @param (int id)
     * @return boolean : is LED off
     *
     */
    boolean IsOff(int id);
};

#endif
