/*
 * Interrupt.h
 *
 *  Created on: Apr 4, 2016
 *      Author: eramox
 */

#ifndef LIBRARIES_LIBERAMOX_INTERRUPT_H_
#define LIBRARIES_LIBERAMOX_INTERRUPT_H_

#include "Arduino.h"

#include "Pin.h"
#include "Utility.h"

namespace liberamox {
using namespace liberamox;

/*
 * Macro to create some code deactivating interrupts
 * temporaly
 */
#define BLOCK_WITHOUT_INTERRUPTS(codeToRun) \
		{\
		deactivateAll();\
		codeToRun;\
		activateAll();\
		}

typedef void (* ISRFuntion) ();

class Interrupt {
private:
	Pin mPin;
	int mInt;
	ISRFuntion mISR;
	int mMode;
	boolean mAttached;
	Validity mValidity;

public:
	/*
	 * Default empty constructor
	 */
	Interrupt();
	/*
	 * Constructor to build a usable interrupt
	 */
	Interrupt(Pin pin, ISRFuntion isr, int mode, int &errval);
	virtual ~Interrupt();

	/*
	 * These functions allows to enabe/disable the Interrupts
	 */
	void enable(int &errval);
	void disable(int &errval);

	/*
	 * These fonctions allows to activate/deactivate
	 * the interruption mechanism
	 * TODO add time function to be proper in this case
	 */
	inline static void deactivateAll() {interrupts();}
	inline static void activateAll() {noInterrupts();}

	inline void setValid() {mValidity = Validity(true);}
	inline void setInvalid() {mValidity = Validity(false);}
};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_INTERRUPT_H_ */
