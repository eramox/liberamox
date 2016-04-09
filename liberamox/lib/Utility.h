/*
 * \file Utility.h
 *
 * \brief This class allow the user to easily
 *        obtain random generate numbers
 *
 * \author Franck LENORMAND <franck.lenormand.fr@gmail.com>
 *
 * \version 0.1
 * \date 04 April 2016
 *
 */

#ifndef LIBRARIES_LIBERAMOX_UTILITY_H_
#define LIBRARIES_LIBERAMOX_UTILITY_H_

#include "Arduino.h"

/*!
 * \namsepace liberamox to wrap all functions of the library
 */
namespace liberamox {
using namespace liberamox;

enum VALIDITY{
	VALID,
	INVALID
};

/*!
 * \class Validity
 */
class Validity {
private:
	int mVal;


public:
	Validity() :mVal(INVALID) {}
	Validity(boolean val){
		mVal = (val)? VALID : INVALID;
	}
	virtual ~Validity(){};
	inline boolean isValid() const {return mVal == VALID;}

};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_UTILITY_H_ */
