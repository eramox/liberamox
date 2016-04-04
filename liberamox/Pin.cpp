#include "Arduino.h"

#include "Pin.h"

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
	}
}


} /* namespace liberamox */
