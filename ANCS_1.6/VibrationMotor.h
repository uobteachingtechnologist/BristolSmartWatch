#ifndef VIBRATIONMOTOR_H
#define VIBRATIONMOTOR_H
#include <Arduino.h>

class VibrationMotor {
  private:
    int pin;
    int defaultValue;
    int currentState;
  public:
    VibrationMotor(int pin, int defaultValue) {
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
     * Turns on the vibration motor.
     *
     * @param (void)
     * @return (void)
     *
     */
    void TurnOn();
    
    /*
     * FUNCTION TurnOff()
     *
     * Turns off the vibration motor.
     *
     * @param (void)
     * @return (void)
     *
     */
    void TurnOff();
    
    /*
     * FUNCTION IsOn()
     *
     * Checks if the vibration motor is on.
     *
     * @param (void)
     * @return boolean : is vibration motor on
     *
     */
    boolean IsOn();
    
    /*
     * FUNCTION IsOff()
     *
     * Checks if the vibration motor is off.
     *
     * @param (void)
     * @return boolean : is vibration motor off
     *
     */
    boolean IsOff();
};

#endif
