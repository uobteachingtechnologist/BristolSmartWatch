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
  hardwareController->Init();
  
	//tilt screen ************************************************************************************
	pinMode(TILT_SWITCH, INPUT_PULLUP);           // set pin to input
	digitalWrite(TILT_SWITCH, LOW);

	//Vibration Motor should be connected to GND  ************************************************************************************
	pinMode(VIBRATION_MOTOR, OUTPUT);
	digitalWrite(VIBRATION_MOTOR, LOW);

  bluetoothManager = new BluetoothManager(hardwareController);
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
	if (hardwareController->IsButtonPressed(0)) {
    if (hardwareController->IsLEDOff(1)){
      hardwareController->TurnOnLED(1);
    } else {
      hardwareController->TurnOffLED(1);
    }
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
	if (hardwareController->IsButtonPressed(1)) {
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
void Watch::DrawScreen() {
	hardwareController->SetFirstPage();
	do {
		hardwareController->DrawNotifications(bluetoothManager->GetNumberOfNotifications());
		hardwareController->DrawTime();
		hardwareController->DrawDate();
		hardwareController->DrawTemperature();
	} while (hardwareController->HasNextPage());
}


