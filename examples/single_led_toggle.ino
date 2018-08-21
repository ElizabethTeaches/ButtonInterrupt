/*
 * Takes an led on pin 0 and a button on pin 4. Pressing 
 * the button toggles the led.
 */
#include <ButtonInterrupt.h>

const int buttonPin = 4;

const int ledPin = 0;

boolean ledState = false;

void setup() {
  pinMode(ledPin, OUTPUT);

  setupButtonInterrupt(buttonPin, toggleLed);

  toggleLed();
}

void loop() {
}

void toggleLed() {
  if(ledState) {
    ledState = false;
    digitalWrite(ledPin, LOW);
  }else {
    ledState = true;
    digitalWrite(ledPin, HIGH);
  }
}

