#ifndef ButtonInterrupt_h
#define ButtonInterrupt_h

#include <Arduino.h>

int lastInterrupt = 0;

void (*buttonListener)();

/**
 * When the specified button is pressed, this calls the listener.
 *
 * @param button the button (pin mode will be set)
 * @param listener the function to call when the button is pressed
 */
void setupButtonInterrupt(int buttonPin, void (*listener)()) {
	if(buttonListener != NULL) {
		return; // Ahh! We can only handle one button but it's too late to warn them
	}
	
	// Setting up the interrupt
	// step 1: pin change mask register (PCMSK) tells the attiny which pins trigger interrupt
	// requests. we only want to get pin change interrupts from our button, so we set the mask
	// to just our button pin.
	PCMSK = _BV(buttonPin);
	
	// step 2: General Interrupt Mask Register: tell the attiny what types of interrupts to listen for
	// PCIE says to listen for pin change interrupts
	GIMSK = _BV(PCIE);
	
	buttonListener = listener;
	
	pinMode(buttonPin, INPUT_PULLUP);
}

ISR(PCINT0_vect) {
	int now = millis();
	if(now - lastInterrupt > 1000) {
		buttonListener();
		lastInterrupt = now;
	}
}

#endif