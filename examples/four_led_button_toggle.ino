/*
 * Takes leds plugged in to pins 0-3 and a button connected on 
 * pin 4. Cycles through one of four different animations when 
 * the button is pressed.
 */
 
#include <ButtonInterrupt.h>

#define CHASER 0
#define ALL_ON_OFF 1
#define ODD_EVEN 2 
#define ALL_ON_OFF_CHASER 3

const int ledPin1 = 0;
const int ledPin2 = 1;
const int ledPin3 = 2;
const int ledPin4 = 3;

const int buttonPin = 4;

const int ledPins[4] = { ledPin1, ledPin2, ledPin3, ledPin4 };
const int numLeds = 4;

int state = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  setupButtonInterrupt(buttonPin, toggleState);
}

void doChaser() {
  for(int ind = 0; ind < numLeds; ind++) {
    digitalWrite(ledPins[ind], HIGH);
    delay(250);
    digitalWrite(ledPins[ind], LOW);
    delay(100);
  }
}

void doAllOnAllOff() {
  for(int ind = 0; ind < numLeds; ind++) {
    digitalWrite(ledPins[ind], HIGH);
  }
  delay(500);
  for(int ind = 0; ind < numLeds; ind++) {
    digitalWrite(ledPins[ind], LOW);
  }
  delay(500);
}

void doOddEven() {
  // even on
  for(int ind = 0; ind < numLeds; ind += 2) {
    digitalWrite(ledPins[ind], HIGH);
  }
  delay(500);
  // even off
  for(int ind = 0; ind < numLeds; ind += 2) {
    digitalWrite(ledPins[ind], LOW);
  }
  // odd on
  for(int ind = 1; ind < numLeds; ind += 2) {
    digitalWrite(ledPins[ind], HIGH);
  }
  delay(500);
  // odd off
  for(int ind = 1; ind < numLeds; ind += 2) {
    digitalWrite(ledPins[ind], LOW);
  }
}

void doAllOnOffChaser() {
  for(int ind = 0; ind < numLeds; ind++) {
    digitalWrite(ledPins[ind], HIGH);
    delay(250);
  }
  for(int ind = 0; ind < numLeds; ind++) {
    digitalWrite(ledPins[ind], LOW);
  }
  delay(250);
}

void loop() {
  if(state == CHASER) {
    doChaser();
  }else if(state == ALL_ON_OFF) {
    doAllOnAllOff();
  }else if(state == ODD_EVEN) {
    doOddEven();
  }else if(state == ALL_ON_OFF_CHASER) {
    doAllOnOffChaser();
  }
}

void toggleState() {
  state = (state + 1) % 4;
}
