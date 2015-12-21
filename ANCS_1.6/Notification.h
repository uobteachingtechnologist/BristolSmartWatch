#ifndef NOTIFICATION_H
#define NOTIFICATION_H 
#include <Arduino.h>

/*
 *  CLASS Notification
 *  
 *  Class used to hold information about
 *  incoming notifications from smartphone.
 */
class Notification {
public:
	Notification() {
	}

	enum NotificationType {
		SMS, EMAIL, INCOMINGCALL, MISSEDCALL
	};
private:
	NotificationType notificationType;
	String senderName = "";
	String notificationText = "";
};
#endif
