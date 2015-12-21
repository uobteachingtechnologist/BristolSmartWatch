#include "Watch.h"

/*
 * FUNCTION HardwareInit()
 * 
 * Performs initial setup of Arduino hardware.
 * 
 * @param (void)
 * @return (void)
 * 
 */
void Watch::HardwareInit() {
	Wire.begin();
	Serial.begin(9600);
	pinMode(ARDUINO_LED, OUTPUT);
	digitalWrite(ARDUINO_LED, LOW);

	//Button number 1 ************************************************************************************
	pinMode(BUTTON_1, INPUT_PULLUP);           // set pin to input
	digitalWrite(BUTTON_1, HIGH);

	//Button number 2 ************************************************************************************
	pinMode(BUTTON_2, INPUT_PULLUP);           // set pin to input
	digitalWrite(BUTTON_2, HIGH);

	//tilt screen ************************************************************************************
	pinMode(TILT_SWITCH, INPUT_PULLUP);           // set pin to input
	digitalWrite(TILT_SWITCH, LOW);

	// FlashLight  ************************************************************************************
	pinMode(EXTERNAL_LED, OUTPUT);
	digitalWrite(EXTERNAL_LED, LOW);

	//Vibration Motor should be connected to GND  ************************************************************************************
	pinMode(VIBRATION_MOTOR, OUTPUT);
	digitalWrite(VIBRATION_MOTOR, LOW);

	bluetoothSerial.begin(9600);
}

/*
 * FUNCTION Update()
 * 
 * Performs check for button state updates, screen updates
 * and checks for bluetooth communication.
 * 
 * @param (void)
 * @return (void)
 * 
 */
void Watch::Update() {
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis >= interval) {
		previousMillis = currentMillis;
		DrawScreen();
		BluetoothCommunications();
	}
	CheckButtons();
}

/*
 * FUNCTION CheckButtons()
 * 
 * Checks the states of all the hardware buttons.
 * 
 * @param (void)
 * @return (void)
 * 
 */
void Watch::CheckButtons() {
	CheckLEDButton();
	CheckScreenOffButton();
}

/*
 * FUNCTION CheckLEDButton()
 * 
 * Checks the state of the LED button and updates the external LED state.     
 * 
 * @param (void)     
 * @return (void)
 * 
 */
void Watch::CheckLEDButton() {
	if (digitalRead(BUTTON_1) == LOW) {
		delay(100);
		isExternalLEDOn = !isExternalLEDOn;
	}
	UpdateExternalLEDState();
}

/*
 * FUNCTION UpdateExternalLEDState()
 * 
 * Updates the external LED state.     
 * 
 * @param (void)     
 * @return (void)
 * 
 */
void Watch::UpdateExternalLEDState() {
	if (isExternalLEDOn) {
		digitalWrite(EXTERNAL_LED, HIGH);
	} else {
		digitalWrite(EXTERNAL_LED, LOW);
	}
}

/*
 * FUNCTION CheckScreenOffButton()
 * 
 * Checks the state of the screen off button and updates the screen power state.
 * 
 * @param (void)
 * @param (void)
 * 
 */
void Watch::CheckScreenOffButton() {
	if (digitalRead(BUTTON_2) == LOW) {
		delay(100);
		isScreenOff = !isScreenOff;
	}
}

/*
 * FUNCTION DrawScreen()
 * 
 * Calls all of the appropriate methods to draw all information 
 * to the screen
 * 
 * @param (void)
 * @return (void)
 * 
 */
void Watch::DrawScreen(void) {
	u8g.firstPage();
	do {
		displayScreen.DrawNotifications(numberOfNotifications);
		displayScreen.DrawTime(clock.GetTime());
		displayScreen.DrawDate(clock.GetDate());
		displayScreen.DrawTemperature(clock.GetTemperature());
	} while (u8g.nextPage());
}

/*
 * FUNCTION BluetoothCommuncations()
 * 
 * Calls BluetoothCommuncation.Read() to read any information
 * over Bluetooth. Writes a notification to the screen if 
 * there is a new notifcation and also vibrates.
 * 
 * @param (void)
 * @return (void)
 * 
 */
void Watch::BluetoothCommunications() {
	bluetoothCommunication.Read();

	if (bluetoothCommunication.GetNewMessage()) {
		displayScreen.DrawMessageSender(bluetoothCommunication.GetName(),
				bluetoothCommunication.GetSubject());
		bluetoothCommunication.SetNewMessage(false);

		//Time to display message
		delay(2000);
	}

	int temp = bluetoothCommunication.GetNumber();
	if (temp != numberOfNotifications && temp > '0') {
		digitalWrite(VIBRATION_MOTOR, HIGH);
		delay(300);
		digitalWrite(VIBRATION_MOTOR, LOW);
	}
	numberOfNotifications = bluetoothCommunication.GetNumber();
}

