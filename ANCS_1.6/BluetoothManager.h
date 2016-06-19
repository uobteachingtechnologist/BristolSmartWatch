#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include "HardwareController.h"
#include <SoftwareSerial.h>
#include <DS3231.h>
#include "Notification.h"
#include "NotificationParser.h"
#include "Screen.h"

/*
 *  CLASS BluetoothCommunication
 *
 *  Communicates with the paired IOS device and saves
 *  information from messages it recieves to member variables.
 */
class BluetoothManager {
  private:
    HardwareController *hardwareController;
    Notification notification;
  public:
    BluetoothManager(HardwareController *hardwareController) {
      this->hardwareController = hardwareController;
    }


    /*
     * FUNCTION GetNotification()
     *
     * Returns the last received notification.
     *
     * @param (void)
     * @return bolean
     *
     */
    void GetNotification(Notification *notification) {
      notification = &this->notification;
    }

    /*
     * FUNCTION CheckNotifications()
     *
     * Checks if there is a new notification and, if so, returns true. Otherwise false.
     *
     * @param (void)
     * @return bolean
     *
     */
    boolean CheckNotifications();
};
#endif
