/*
 * Pin.h
 *
 *  Created on: Apr 3, 2016
 *      Author: eramox
 *
 * Allow to control the pin on the board and
 * provide utility functions
 */

#ifndef LIBRARIES_LIBERAMOX_PIN_H_
#define LIBRARIES_LIBERAMOX_PIN_H_

#include "Utility.h"

namespace liberamox {
using namespace liberamox;

class Pin {
private:
	int mPin;
	Validity mValidity;

public:
	Pin();
	Pin(int pin);
	virtual ~Pin();

	/* Switch the Pin ON
	 */
	void on();

	/* Switch the Pin ON
	 */
	void off();

	inline int getValue() {return mPin;}
	inline boolean isValid() {return mValidity.isValid();}

	inline void setValid() {mValidity = Validity(true);}
	inline void setInvalid() {mValidity = Validity(false);}

};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_PIN_H_ */
