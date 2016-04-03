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

class HardwareAdapter {
public:
	HardwareAdapter();
	virtual ~HardwareAdapter();
};

#endif /* LIBRARIES_LIBERAMOX_HARDWAREADAPTER_H_ */
