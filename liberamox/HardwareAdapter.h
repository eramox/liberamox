/*
 * HardwareAdapter.h
 *
 *  Created on: Apr 3, 2016
 *      Author: eramox
 *
 * Virtual class to represent a controller
 * for an hardware:
 * - multiplexer
 * - register
 */

#ifndef LIBRARIES_LIBERAMOX_HARDWAREADAPTER_H_
#define LIBRARIES_LIBERAMOX_HARDWAREADAPTER_H_

namespace liberamox {
using namespace liberamox;

class HardwareAdapter {
public:
	HardwareAdapter();
	virtual ~HardwareAdapter(){};
};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_HARDWAREADAPTER_H_ */
