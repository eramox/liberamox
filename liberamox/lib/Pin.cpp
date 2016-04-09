#include "../lib/Pin.h"

#include "Arduino.h"


namespace liberamox {
using namespace liberamox;

Pin::Pin()
	: mPin(0), mValidity(Validity(false))
{
}

Pin::Pin(int pin) : mPin(pin) {
	if (pin < 0) {
		Pin();
	} else {
		mPin = pin;
		mValidity = Validity(true);
	}
}


} /* namespace liberamox */
