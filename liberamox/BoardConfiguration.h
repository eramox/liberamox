/*
 * BoardConfiguration.h
 *
 *  Created on: Apr 4, 2016
 *      Author: eramox
 */

#ifndef LIBRARIES_LIBERAMOX_BOARDCONFIGURATION_H_
#define LIBRARIES_LIBERAMOX_BOARDCONFIGURATION_H_

namespace liberamox {
using namespace liberamox;

#include "Arduino.h"

class BoardConfiguration {
public:
	static inline boolean checkPinMode(int mode) {
		return     mode == LOW
				|| mode == CHANGE
				|| mode == RISING
				|| mode == FALLING
	#ifdef BOARD_DUE
				|| mode == HIGH
	#endif
				;
	}

};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_BOARDCONFIGURATION_H_ */
