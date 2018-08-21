# ButtonInterrupt

This is a small wrapper around pin-controlled interrupts. It takes in a pin and a function and runs the function whenever the state of the pin changes (but at a maximum of once per second). This works beautifully on tactile buttons.

## Example

From examples/single_led_toggle:

```cpp
/*
 * Takes an led on pin 0 and a button on pin 4. Pressing 
 * the button toggles the led.
 */
#include <ButtonInterrupt.h>

const int buttonPin = 4;

const int ledPin = 0;

bool ledState = false;

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
```

## Installation

Download the source as a zip file, extract the zip anywhere, copy the ButtonInterrupt folder into Documents/Arduino/libraries such that Documents/Arduino/libraries/ButtonInterrupt/ButtonInterrupt.h is a file.