/*
 * Hardware.h
 *
 *  Created on: Apr 3, 2016
 *      Author: eramox
 *
 * Virtual class to represent which
 * represent any hardware and allow
 * interop capabilities as:
 * - LED
 * - Switch
 */

#ifndef LIBRARIES_LIBERAMOX_HARDWARE_H_
#define LIBRARIES_LIBERAMOX_HARDWARE_H_

namespace liberamox {
using namespace liberamox;

class Hardware {
public:
	Hardware();
	virtual ~Hardware();
};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_HARDWARE_H_ */
