/*
 * Utility.h
 *
 *  Created on: Apr 4, 2016
 *      Author: eramox
 */

#ifndef LIBRARIES_LIBERAMOX_UTILITY_H_
#define LIBRARIES_LIBERAMOX_UTILITY_H_

namespace liberamox {
using namespace liberamox;

#include "Arduino.h"

enum VALIDITY{
	VALID,
	INVALID
};

class Validity {
private:
	int mVal;


public:
	Validity() :mVal(INVALID) {}
	Validity(boolean val){
		mVal = (val)? VALID : INVALID;
	}
	virtual ~Validity();
	inline boolean isValid() {return mVal == VALID;}

};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_UTILITY_H_ */
