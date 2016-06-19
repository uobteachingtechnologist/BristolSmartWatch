#include <SoftwareSerial.h>
#include "U8glib.h"
#include <DS3231.h>
#include <Wire.h>
#include "Watch.h"
#include "HardwareController.h"


Watch watch;

/*
 * FUNCTION setup()
 *
 * Configures all of the states of the hardware
 *
 * @param (void)
 * @return (void)
 *
 */
void setup() {
  watch.HardwareInit();
}

/*
 * FUNCTION Loop()
 *
 * Makes appropriate function calls each time it is called
 * by the arduino
 *
 * @param (void)
 * @return (void)
 *
 */
void loop() {
  watch.Update();
}
