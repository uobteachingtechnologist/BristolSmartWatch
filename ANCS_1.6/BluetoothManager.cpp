#include "BluetoothManager.h"

/*
 * FUNCTION CheckNotifications()
 *
 * Checks if there is a new notification and, if so, returns true. Otherwise false.
 *
 * @param (void)
 * @return bolean
 *
 */
boolean BluetoothManager::CheckNotifications() {
  String data = hardwareController->GetData();
  if (data != "") {
    Notification *notification;
    ParseNotification(data, notification);
    return true;
  }
  return false;
}



