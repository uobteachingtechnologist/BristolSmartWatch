#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button {
  private:
    int pin;
    int defaultValue;
    int previousState;
  public:
    Button(int pin, int defaultValue) {
      this->pin = pin;
      this->defaultValue = defaultValue;
      this->previousState = defaultValue;
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
     * FUNCTION IsPressed()
     *
     * Checks whether the button is pressed.
     *
     * @param (void)
     * @return boolean : is button pressed
     *
     */
    boolean IsPressed();
};

#endif
