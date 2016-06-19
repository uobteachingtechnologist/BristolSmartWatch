#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <Arduino.h>
#include <SoftwareSerial.h>

/*
 *  CLASS Bluetooth
 *
 *  This class controls bluetooth communication
 *  through specific methods.
 */
class Bluetooth {
  private:
    const int rx = 10;
    const int tx = 16;
    SoftwareSerial bluetoothSerial; // RX, TX
  public:
    Bluetooth()
      :  bluetoothSerial(rx, tx) {

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
     * FUNCTION IsDataAvailable()
     *
     * Returns data available on the bluetooth serial.
     *
     * @param (void)
     * @return String : data
     *
     */
    boolean IsDataAvailable();


    /*
     * FUNCTION GetData()
     *
     * Returns data available on the bluetooth serial.
     *
     * @param (void)
     * @return String : data
     *
     */
    String GetData();

    /*
     * FUNCTION SendData()
     *
     * Configures the hardware.
     *
     * @param (char* data)
     * @return (void)
     *
     */
    void SendData(char *data);
};

#endif
