#include "Notification.h"

unsigned char Notification::GetEventId() {
  return eventId;
}

void Notification::SetEventId(unsigned char eventId) {
  this->eventId = eventId;
}

unsigned char Notification::GetEventFlags() {
  return eventFlags;
}

void Notification::SetEventFlags(unsigned char eventFlags) {
  this->eventFlags = eventFlags;
}

unsigned char Notification::GetCategoryId() {
  return categoryId;
}

void Notification::SetCategoryId(unsigned char catergoryId) {
  this->categoryId = categoryId;
}

String Notification::GetNotificationUid() {
  return notificationUid;
}

void Notification::SetNotificationUid(String notificationUid) {
  this->notificationUid = notificationUid;
}

