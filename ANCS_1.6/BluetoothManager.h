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
    Notification *notification;
    int numberOfNotifications = 0;
  public:
    BluetoothManager(HardwareController *hardwareController) {
      this->hardwareController = hardwareController;
    }


    /*
     * FUNCTION GetNotification()
     *
     * Returns the last received notification.
     *
     * @param (Notification : notification)
     * @return (void)
     *
     */
    void GetNotification(Notification *notification) {
      notification = this->notification;
    }

    /*
     * FUNCTION CheckNotifications()
     *
     * Checks if there is a new notification and, if so, returns true. Otherwise false.
     *
     * @param (void)
     * @return bolean : new notification received
     *
     */
    boolean CheckNotifications();

    /*
     * FUNCTION GetNumberOfNotifications()
     *
     * Returns number of notifications.
     *
     * @param (void)
     * @return int : number of notifications
     *
     */
    int GetNumberOfNotifications();

    /*
     * FUNCTION AlertUser()
     *
     * Alerts the user to a new notification.
     *
     * @param (void)
     * @return (void)
     *
     */
    void AlertUser();
};
#endif
