#ifndef NOTIFICATIONPARSER_H
#define NOTIFICATIONPARSER_H
#include "Arduino.h"
#include "Notification.h"

/*
 * FUNCTION CreateGetMessageTextRequest()
 *
 * Returns a string containing the command for the message body for given notification.
 *
 * @param (Notification *notification)
 * @return (String)
 *
 */
String CreateGetMessageTextRequest(Notification *notification);

/*
 * FUNCTION CreateGetTitleRequest()
 *
 * Returns a string containing the command for the message title for given notification.
 *
 * @param (Notification *notification)
 * @return (String)
 *
 */
String CreateGetTitleRequest(Notification *notification);


/*
 * FUNCTION ParseNotification()
 *
 * Parses string into notification.
 *
 * @param (String buffer, Notification *notification)
 * @return boolean : did buffer parse correctly
 *
 */
boolean ParseNotification(String buffer, Notification *notification);

#endif
