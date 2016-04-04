/*
 * \file BoardConfiguration.h
 *
 * \brief This class handle a borad configuration
 *
 * \author Franck LENORMAND <franck.lenormand.fr@gmail.com>
 *
 * \version 0.1
 * \date 04 April 2016
 *
 */

#ifndef LIBRARIES_LIBERAMOX_BOARDCONFIGURATION_H_
#define LIBRARIES_LIBERAMOX_BOARDCONFIGURATION_H_

#include "Arduino.h"

/*
 * \namsepace liberamox to wrap all functions of the library
 */
namespace liberamox {
using namespace liberamox;

/*
 * \class BoardConfiguration
 */
class BoardConfiguration {
public:
	/*
	 * \brief check if the mode for the pin is correct
	 *
	 * \param[in] mode the mode to check
	 * \return true if the mode can be used for a pin, else false
	 */
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
