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
    notification = new Notification();
    if (ParseNotification(data, notification)) {
      if (notification->GetEventId() == AncsNotificationEventIdAdded) {
        numberOfNotifications++;
      } else if (notification->GetEventId() == AncsNotificationEventIdRemoved) {
        if (numberOfNotifications > 0)
          numberOfNotifications--;
      }

      AlertUser();

      return true;
    }
  }
  return false;
}

int BluetoothManager::GetNumberOfNotifications() {
  CheckNotifications();
  return numberOfNotifications;
}

void BluetoothManager::AlertUser() {
  // Flash LED / vibration motor
  hardwareController->TurnOnLED(1);
  hardwareController->TurnOnVibrationMotor();
  delay(200);
  hardwareController->TurnOffLED(1);
  hardwareController->TurnOffVibrationMotor();
  delay(200);
  hardwareController->TurnOnLED(1);
  hardwareController->TurnOnVibrationMotor();
  delay(200);
  hardwareController->TurnOffLED(1);
  hardwareController->TurnOffVibrationMotor();
}

