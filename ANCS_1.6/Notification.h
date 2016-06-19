#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <Arduino.h>

enum AncsNotificationEventId {
  AncsNotificationEventIdAdded    = 0,
  AncsNotificationEventIdModified = 1,
  AncsNotificationEventIdRemoved  = 2
};

enum AncsNotificationEventFlags {
  AncsNotificationEventFlagsSilent         = 1,
  AncsNotificationEventFlagsImportant      = 2,
  AncsNotificationEventFlagsPositiveAction = 4,
  AncsNotificationEventFlagsNegativeAction = 8
};

enum AncsNotificationCategoryId {
  AncsNotificationCategoryIdOther              = 0,
  AncsNotificationCategoryIdIncomingCall       = 1,
  AncsNotificationCategoryIdMissedCall         = 2,
  AncsNotificationCategoryIdVoicemail          = 3,
  AncsNotificationCategoryIdSocial             = 4,
  AncsNotificationCategoryIdSchedule           = 5,
  AncsNotificationCategoryIdEmail              = 6,
  AncsNotificationCategoryIdNews               = 7,
  AncsNotificationCategoryIdHealthAndFitness   = 8,
  AncsNotificationCategoryIdBusinessAndFinance = 9,
  AncsNotificationCategoryIdLocation           = 10,
  AncsNotificationCategoryIdEntertainment      = 11
};

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

    /*
     * FUNCTION GetEventId()
     *
     * Returns the event id of the notification.
     *
     * @param (void)
     * @return (unsigned char eventId)
     *
     */
    unsigned char GetEventId();

    /*
    * FUNCTION SetEventId()
    *
    * Sets the event id of the notification.
    *
    * @param (unsigned char eventId)
    * @return (void)
    *
    */
    void SetEventId(unsigned char eventId);

    /*
    * FUNCTION GetEventFlags()
    *
    * Returns the event flags of the notification.
    *
    * @param (void)
    * @return (unsigned char eventFlags)
    *
    */
    unsigned char GetEventFlags();

    /*
    * FUNCTION SetEventFlags()
    *
    * Sets the event flags of the notification.
    *
    * @param (unsigned char eventFlags)
    * @return (void)
    *
    */
    void SetEventFlags(unsigned char eventFlags);

    /*
    * FUNCTION GetCategoryId()
    *
    * Returns the category id of the notification.
    *
    * @param (void)
    * @return (unsigned char categoryId)
    *
    */
    unsigned char GetCategoryId();

    /*
    * FUNCTION SetCategoryId()
    *
    * Sets categoryId of notification.
    *
    * @param (unsigned char categoryId)
    * @return (void)
    *
    */
    void SetCategoryId(unsigned char categoryId);

    /*
    * FUNCTION GetNotificationUid()
    *
    * Returns the notification UID.
    *
    * @param (void)
    * @return (String notificationUid)
    *
    */
    String GetNotificationUid();

    /*
    * FUNCTION SetNotificationUid()
    *
    * Sets the notification UID.
    *
    * @param (String notificationUid)
    * @return (void)
    *
    */
    void SetNotificationUid(String notificationUid);

  private:
    unsigned char eventId;
    unsigned char eventFlags;
    unsigned char categoryId;
    String notificationUid;
};
#endif
