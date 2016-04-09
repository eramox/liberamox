/*!
 * \file Pin.h
 *
 * \brief This class allow the user to easily
 *        interact with interrupts
 *
 * \author Franck LENORMAND <franck.lenormand.fr@gmail.com>
 *
 * \version 0.1
 * \date 04 April 2016
 *
 */

#ifndef LIBRARIES_LIBERAMOX_PIN_H_
#define LIBRARIES_LIBERAMOX_PIN_H_

#include "../lib/Utility.h"

/*!
 * \namespace liberamox to wrap all functions of the library
 */
namespace liberamox {
using namespace liberamox;

/*!
 * class Pin
 */
class Pin {
private:
	int mPin;
	Validity mValidity;

public:
	Pin();
	Pin(int pin);
	virtual ~Pin(){};

	/*! \brief Switch the Pin ON
	 */
	inline void on() const {digitalWrite(mPin, HIGH);}

	/*! \brief Switch the Pin ON
	 */
	inline void off() const {digitalWrite(mPin, LOW);}

	inline void blink(int time) const {on();delay(time);off();}

	inline int getValue() const {return mPin;}
	inline boolean isValid() const {return mValidity.isValid();}

	inline void setValid() {mValidity = Validity(true);}
	inline void setInvalid() {mValidity = Validity(false);}

};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_PIN_H_ */
