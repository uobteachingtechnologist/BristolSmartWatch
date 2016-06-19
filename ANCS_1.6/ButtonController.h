#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H
#include <Arduino.h>
#include "Button.h"

class ButtonController {
  private:
    Button *buttons[2];
    
  public:
    ButtonController() {
      buttons[0] = new Button(8, HIGH);
      buttons[1] = new Button(6, HIGH);
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
     * FUNCTION IsButtonPressed()
     *
     * Checks whether the specified button is pressed.
     *
     * @param (int id)
     * @return boolean : is button pressed
     *
     */
    boolean IsButtonPressed(int id);
};

#endif
