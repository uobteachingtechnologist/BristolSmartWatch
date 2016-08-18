#include "NotificationParser.h"
#include "Notification.h"

/*
 * Using these command values: https://developer.apple.com/library/ios/documentation/CoreBluetooth/Reference/AppleNotificationCenterServiceSpecification/Appendix/Appendix.html#//apple_ref/doc/uid/TP40013460-CH3-SW5
 * May need changing.
 */

String CreateGetMessageTextRequest(Notification *notification) {
  return String("AT+ANCS") + notification->GetNotificationUid() + String("392");
}

String CreateGetTitleRequest(Notification *notification) {
  return String("AT+ANCS") + notification->GetNotificationUid() + String("122");
}


boolean ParseNotification(String buffer, Notification *notification) {
  // https://developer.apple.com/library/ios/documentation/CoreBluetooth/Reference/AppleNotificationCenterServiceSpecification/Specification/Specification.html#//apple_ref/doc/uid/TP40013460-CH1-SW7
  // http://files.meetup.com/2563682/iot-ancs.pdf
  Serial.println(buffer);
  if (buffer.length() != 16 || !buffer.startsWith("OK+ANCS")) // incorrect message
    return false;
  buffer.remove(0, 8);
  notification->SetEventId((unsigned char)(buffer[0]) - '0');
  notification->SetCategoryId((unsigned char)(buffer[1]) - '0');
  notification->SetCategoryCount(buffer.substring(2,4).toInt());
  notification->SetNotificationUid(buffer.substring(4));
  return true;
}

