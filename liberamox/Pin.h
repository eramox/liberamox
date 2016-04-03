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

class Pin {
	int mPin;
public:
	Pin(int pin);
	virtual ~Pin();

	/* Switch the Pin ON
	 */
	void on();

	/* Switch the Pin ON
	 */
	void off();

};

#endif /* LIBRARIES_LIBERAMOX_PIN_H_ */
