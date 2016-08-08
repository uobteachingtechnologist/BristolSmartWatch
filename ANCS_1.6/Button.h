#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>

class Button {
  private:
    int pin;
    int buttonState = HIGH; //this variable tracks the state of the button, low if not pressed, high if pressed
    int outputState = 0; //this variable tracks the state of the LED, negative if off, positive if on
 
    long lastDebounceTime = 0;  // the last time the output pin was toggled
    long debounceDelay = 100;    // the debounce time; increase if the output flickers
 
  public:
    Button(int pin, int defaultValue) {
      this->pin = pin;
      this->buttonState = buttonState;
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
