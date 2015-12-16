#include "switches.h"
#include <SoftwareSerial.h>

void inSw::init(uint8_t sw) {
	pinNum = sw;
	pinMode(sw, INPUT_PULLUP);	// set pin to input with an internal pullup resistor
	digitalWrite(sw, HIGH);		// Enable pullup
	swState = 0;
	lastPush = millis();
};

boolean inSw::readState() {
	swState = digitalRead(pinNum);
	return (swState);
}
/*
boolean inSw::newPush() {
	swState = digitalRead(pinNum);
	if (swState != lastState) {		// If switch change, debounce:
		if ((millis() - lastPush > debTime)) {	// no button change
			lastPush == millis();
			lastState = swState;
			if (!lastState)			// indicate new pB when depressed, not when released
				return 1;
			else
				return 0;
		}
	}
	else {
		return 0;		//no switch change
	}
} */