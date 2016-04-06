/*
 * \file Interrupt.h
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

#ifndef LIBRARIES_LIBERAMOX_INTERRUPT_H_
#define LIBRARIES_LIBERAMOX_INTERRUPT_H_

#include "Arduino.h"

#include "Pin.h"
#include "Utility.h"

/*
 * \namespace liberamox to wrap all functions of the library
 */
namespace liberamox {
using namespace liberamox;

/*
 * \def BLOCK_WITHOUT_INTERRUPTS Macro to create some code
 * deactivating interrupts temporaly
 */
#define BLOCK_WITHOUT_INTERRUPTS(codeToRun) \
		{\
		deactivateAll();\
		codeToRun;\
		activateAll();\
		}

/*
 * class Interrupt
 */
class Interrupt {
public:
	/*
	 * \def define of the format of an <ISRFunction>
	 */
	typedef void (* ISRFuntion)();

private:
	Pin mPin;
	int mInt;
	const ISRFuntion * mISR;
	int mMode;
	boolean mAttached;
	Validity mValidity;

public:
	/*
	 * \brief Default empty constructor, build an instance which is not valid
	 */
	Interrupt();

	/*
	 * \brief Constructor to build a usable interrupt
	 *
	 * \param[in] pin <Pin> on which the interrupts will be
	 * \param[in] isr <ISRFunction> function called when the interrupts is triggered
	 * \param[in] mode the mode of transition on which the interrupts is triggered
	 * \param[in,out] errval error code after execution of the function
	 */
	Interrupt(const Pin pin, const ISRFuntion *isr, const int mode, int &errval);
	virtual ~Interrupt(){};

	/*
	 * These functions allows to enabe/disable the Interrupts
	 */
	/*
	 * \brief enable an interrupts
	 * \param[in] errval error code
	 */
	void enable(int &errval);
	/*
	 * \brief disable an interrupts
	 * \param[in] errval error code
	 */
	void disable(int &errval);

	/*
	 * These fonctions allows to activate/deactivate
	 * the interruption mechanism
	 * TODO add time function to be proper in this case
	 */
	/*
	 * \brief deactivate interrupts mechanism on the system
	 */
	inline static void deactivateAll() const {interrupts();}
	/*
	 * \brief activate interrupts mechanism on the system
	 */
	inline static void activateAll() const {noInterrupts();}

	inline void setValid() {mValidity = Validity(true);}
	inline void setInvalid() {mValidity = Validity(false);}
};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_INTERRUPT_H_ */
