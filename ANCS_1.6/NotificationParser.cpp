#include "NotificationParser.h"
#include "Notification.h"

/*
 * Using these command values: https://developer.apple.com/library/ios/documentation/CoreBluetooth/Reference/AppleNotificationCenterServiceSpecification/Appendix/Appendix.html#//apple_ref/doc/uid/TP40013460-CH3-SW5
 * May need changing.
 */

String CreateGetMessageTextRequest(Notification *notification) {
  return String("AT+ANCS:0") + notification->GetNotificationUid() + String("3FF");
}

String CreateGetTitleRequest(Notification *notification) {
  return String("AT+ANCS:1") + notification->GetNotificationUid() + String("3FF");
}


void ParseNotification(String buffer, Notification *notification) {
  // https://developer.apple.com/library/ios/documentation/CoreBluetooth/Reference/AppleNotificationCenterServiceSpecification/Specification/Specification.html#//apple_ref/doc/uid/TP40013460-CH1-SW7
  buffer.remove(0, 8);
  notification->SetEventId((unsigned char)(buffer[0] - '0'));
  notification->SetEventFlags((unsigned char)(buffer[1] - '0'));
  notification->SetCategoryId((unsigned char)(buffer[2] - '0'));
  notification->SetNotificationUid(buffer.substring(4));
}

