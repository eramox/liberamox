/*
 * Pin.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: eramox
 */

#include "Arduino.h"

#include "Pin.h"

namespace liberamox {
using namespace liberamox;

Pin::Pin()
	: mPin(0)
{
	mValidity = Validity(false);
}

Pin::Pin(int pin) : mPin(pin) {
	if (pin < 0) {
		Pin();
	} else {
		mPin = pin;
	}
}

Pin::~Pin() {
}


void Pin::on() {
	digitalWrite(mPin, HIGH);
}

void Pin::off() {
	digitalWrite(mPin, LOW);
}

} /* namespace liberamox */
