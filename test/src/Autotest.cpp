/*
 * Autotest.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: root
 */

#include "Arduino.h"

#include "../include/Autotest.h"

Autotest::Autotest(int freq): mFreq(freq) {
	// TODO Auto-generated constructor stub
}

Autotest::~Autotest() {
	// TODO Auto-generated destructor stub
}

void Autotest::run() {
	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(mFreq);              // wait for a second
	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	delay(mFreq);
}

