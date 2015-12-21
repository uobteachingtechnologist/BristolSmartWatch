#ifndef BLUETOOTHCOMMUNICATION_H
#define BLUETOOTHCOMMUNICATION_H 

#include <SoftwareSerial.h>
#include <DS3231.h>
#include "Notification.h"
#include "Screen.h"

/*
 *  CLASS BluetoothCommunication
 *  
 *  Communicates with the paired IOS device and saves
 *  information from messages it recieves to member variables.
 */
class BluetoothCommunication {
private:
	SoftwareSerial *mySerial;
	boolean newMessage = false;
	char Title[15];
	char Message[15];
	boolean printed = true;
	boolean UID = false;
	boolean SMS = false;
	boolean EMAIL = false;
	boolean MISSEDCALL = false;
	boolean INCOMINGCALL = false;
	boolean Display = true;
	String buffer = "";
	String temp = "";
	String Name = "";
	String Subject2 = "";
	String parsedSubject2 = "";
	String Line1 = "";
	String Line2 = "";
	const int ANCS8SIZE = 8 + 8;
	const int INDEX_CATEGORY = 9;
	char Number = '0';
	char Index = '0';
public:
	BluetoothCommunication(SoftwareSerial *mySerial) {
		this->mySerial = mySerial;
	}

	/*
	 * FUNCTION Read()
	 *
	 * Recieves a string from the phone. This string contains a unique id identifying the notifcation.
	 * The rest of the code extracts the the last four digits of the unique string. It then uses this
	 * unique identifier to make another request to the phone for information about that specific
	 * notification so that it can be displayed on the screen of the watch. The name of the sender
	 * and subject of the message are set member variables of the class 'Name' and 'Subject2' and these
	 * can be accessed through the corresponding Get methods.
	 *
	 * @param (void)
	 * @return (void)
	 *
	 */
	void Read();

	/*
	 * FUNCTION GetSubject()
	 *
	 * Returns member variable 'Subject2'
	 *
	 * @param (void)
	 * @return String: returns the subject of the notification
	 *
	 */
	String GetSubject() {
		return Subject2;
	}

	/*
	 * FUNCTION GetName()
	 *
	 * Returns member variable 'Name'
	 *
	 * @param (void)
	 * @return String: returns the Name of the notification Sender
	 *
	 */
	String GetName() {
		return Name;
	}

	/*
	 * FUNCTION GetnewMessage()
	 *
	 * Returns member variable 'newMessage'
	 *
	 * @param (void)
	 * @return bool: Should be true if new message has been recieved and
	 * flase otherwise
	 *
	 */
	bool GetNewMessage() {
		return newMessage;
	}

	/*
	 * FUNCTION SetnewMessage()
	 *
	 * Sets the value of member variable 'newMessage'
	 *
	 * @param (bool value) value to be set
	 * @return bool: value of 'newMessage'
	 */
	void SetNewMessage(bool value) {
		newMessage = value;
	}

	/*
	 * FUNCTION GetNumber()
	 *
	 * Returns member variable 'Number'
	 *
	 * @param (void)
	 * @return bool: is the number of new messages recieved
	 */
	int GetNumber() {
		return Number;
	}
};
#endif
