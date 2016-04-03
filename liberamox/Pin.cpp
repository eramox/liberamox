/*
 * Pin.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: eramox
 */

#include "Arduino.h"

#include "Pin.h"

Pin::Pin(int pin) : mPin(pin) {
	// TODO Auto-generated constructor stub

}

Pin::~Pin() {
	// TODO Auto-generated destructor stub
}


void Pin::on() {
	digitalWrite(mPin, HIGH);
}

void Pin::off() {
	digitalWrite(mPin, LOW);
}

