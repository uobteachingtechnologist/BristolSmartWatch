#include "Controller.h"

/*
 * FUNCTION Setup()
 * 
 * Performs initial setup of Arduino hardware.
 * 
 * @param (void)
 * @return (void)
 * 
 */
void Controller::Setup(){
  Wire.begin();
  Serial.begin(9600);
  pinMode(arduinoLED, OUTPUT);
  digitalWrite(arduinoLED, LOW);

  //Button number 1 ************************************************************************************
  pinMode(buttonstate, INPUT_PULLUP);           // set pin to input
  digitalWrite(buttonstate, HIGH);


  //Button number 2 ************************************************************************************
  pinMode(sleepwake, INPUT_PULLUP);           // set pin to input
  digitalWrite(sleepwake, HIGH);

  //tilt screen ************************************************************************************
  pinMode(tiltscreen, INPUT_PULLUP);           // set pin to input
  digitalWrite(tiltscreen, LOW);

  // FlashLight  ************************************************************************************
  pinMode(led, OUTPUT);
  digitalWrite(led , LOW);

  //Vibration Motor should be connected to GND  ************************************************************************************
  pinMode(vibrate, OUTPUT);
  digitalWrite(vibrate, LOW);

  mySerial.begin(9600);
}

/*
 * FUNCTION Loop()
 * 
 * Performs check for button state updates, screen updates
 * and checks for bluetooth communication.
 * 
 * @param (void)
 * @return (void)
 * 
 */
void Controller::Loop(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time we last checked for updates
    previousMillis = currentMillis;
    CheckButtons();
    DrawScreen();
    BluetoothCommunications();
  }
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
void Controller::CheckButtons() {
  //Goes to notification page
  if (digitalRead(buttonstate) == LOW) {
    delay(100);
    if (screen == 0) {
      screen = 1;
    }
    else {
      screen = 0;
    }
  }

  // Turns the screen off
  if (digitalRead(sleepwake) == LOW) {
    delay(100);
    if (screensleep == 0) {
      screensleep = 1;
    }
    else {
      screensleep = 0;
    }
  }

  // Turns on the Flash Light
  if (screen == 1) {
    digitalWrite(led , HIGH);
  } else {
    digitalWrite(led, LOW);
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
void Controller::DrawScreen(void) {
  u8g.firstPage();
  do {
    displayScreen.DrawNotifications(number);
    displayScreen.DrawTime(clock.GetTime());
    displayScreen.DrawDate(clock.GetDate());
    displayScreen.DrawTemperature(clock.GetTemperature());
  }
  while ( u8g.nextPage() );
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
void Controller::BluetoothCommunications() {
  bluetoothCommunication.Read();
  
  if(bluetoothCommunication.GetNewMessage()) {
    displayScreen.DrawMessageSender(bluetoothCommunication.GetName(), 
                                    bluetoothCommunication.GetSubject());
    bluetoothCommunication.SetNewMessage(false);
   
    //Time to display message
    delay(2000); 
  }
  
  int temp = bluetoothCommunication.GetNumber();
  if(temp != number && temp > '0') {
    digitalWrite(vibrate, HIGH);
    delay(300);
    digitalWrite(vibrate, LOW);
  }
  number = bluetoothCommunication.GetNumber();
}

