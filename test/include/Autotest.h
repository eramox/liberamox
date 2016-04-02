/*
 * Autotest.h
 *
 *  Created on: Apr 2, 2016
 *      Author: root
 */

#ifndef SRC_AUTOTEST_H_
#define SRC_AUTOTEST_H_


class Autotest {
private:
	unsigned long int mFreq;
public:
	Autotest(int freq = 1000);
	virtual ~Autotest();

	void run();
};

#endif /* SRC_AUTOTEST_H_ */
