#include "Bluetooth.h"

/*
 * FUNCTION Init()
 *
 * Configures the hardware.
 *
 * @param (void)
 * @return (void)
 *
 */
void Bluetooth::Init() {
  bluetoothSerial.begin(9600);
}

/*
 * FUNCTION IsDataAvailable()
 *
 * Checks whether there is data available on the bluetooth serial. Returns true if available.
 *
 * @param (void)
 * @return boolean : available
 *
 */
boolean Bluetooth::IsDataAvailable() {
  return bluetoothSerial.available();
}

/*
 * FUNCTION GetData()
 *
 * Returns data available on the bluetooth serial.
 *
 * @param (void)
 * @return String : data
 *
 */
String Bluetooth::GetData() {
  String data = "";
  while (bluetoothSerial.available()) {
    char c = (char) bluetoothSerial.read();

    if ((int) c != 0) {
      data += c;
    }
  }
  return data;
}

/*
 * FUNCTION SendData()
 *
 * Configures the hardware.
 *
 * @param (char* data)
 * @return (void)
 *
 */
void Bluetooth::SendData(char *data) {
  bluetoothSerial.write(data);
}

