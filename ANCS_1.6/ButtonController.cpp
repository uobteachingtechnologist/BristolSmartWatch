#include "ButtonController.h"

/*
 * FUNCTION Init()
 *
 * Configures the hardware.
 *
 * @param (void)
 * @return (void)
 *
 */
void ButtonController::Init() {
  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
    buttons[i]->Init();
  }
}

/*
 * FUNCTION IsButtonPressed()
 *
 * Checks whether the specified button is pressed.
 *
 * @param (int id)
 * @return boolean : is button pressed
 *
 */
boolean ButtonController::IsButtonPressed(int id) {
  return buttons[id]->IsPressed();
}

