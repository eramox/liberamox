/*
 * \file RandomGenerator.h
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

#ifndef LIBRARIES_LIBERAMOX_RANDOMGENERATOR_H_
#define LIBRARIES_LIBERAMOX_RANDOMGENERATOR_H_

#include "Arduino.h"

#include "Pin.h" /* For pin used in seed generation*/
#include "Utility.h"

/*
 * \namsepace liberamox to wrap all functions of the library
 */
namespace liberamox {
using namespace liberamox;

/*
 * \class RandomGenerator
 */
class RandomGenerator {

public:
	/*
	 * \enum SEED_TYPE to specify the type of seed
	 *       to use for the random generator
	 */
	enum SEED_TYPE {
		FIXED,
		PIN_READ,
		BASE_GENERATED
	};


private:
	static RandomGenerator m_instance;
	int mSeed;
	SEED_TYPE mSeedType;
	Validity mValidity;

	/*
	 * Basic constructor
	 */
	RandomGenerator();
	/*
	 * \brief Basic destructor
	 */
	virtual ~RandomGenerator(){};

	/*
	 * \brief private function used internally
	 *        use <getRandomGenerator> to obtain
	 *        an instance
	 *
	 * \param[in] pin the <Pin> to use to have a random seed
	 * \return Instance of <RandomGenerator>
	 */
	RandomGenerator(const Pin pin);

	/*
	 * \brief private function used internally
	 *        use <getRandomGenerator> to obtain
	 *        an instance
	 *
	 * \param[in] seed the seed value to use
	 * \return Instance of <RandomGenerator>
	 */
	RandomGenerator(const int seed);

	//RandomGenerator& operator= (const RandomGenerator&){};
	//RandomGenerator (const RandomGenerator&){}

	/*
	 * \param[in] valid set the validity of the instance
	 */
	inline void setValidity(boolean valid){mValidity = Validity(valid);}
	/*
	 * \param[in] seed set the seed value used
	 */
	inline void setSeed(int seed){mSeed = seed;}
	/*
	 * \param[in] seedType set the type of seed used in the instance
	 */
	inline void setSeedType(SEED_TYPE seedType){mSeedType = seedType;}

public:

	/*
	 * \brief Function to obtain an instance of RandomGenerator
	 *        Once a RandomGenerator is instanced, all other
	 *        Instantiation will be the same
	 *
	 * \param[in] seedtype the <SEED_TYPE> to use for the generator
	 * \param[in] seed the seed value to use
	 *
	 * \return an instance of RandomGenerator
	 */
	static RandomGenerator& getInstance(RandomGenerator::SEED_TYPE seedtype, void * seed);

	/*
	 * \brief obtain the type of seed used
	 * \return the <SEED_TYPE> used for the generator
	 */
	inline SEED_TYPE getSeedType() const {return mSeedType;}

	/*
	 * \brief obtain the value of seed used
	 * \return the seed used for the generator
	 */
	inline int getSeed() const {return mSeed;}

	/*
	 * \brief obtain a random value
	 * \return a random value in the interval [min ; max[
	 */
	inline long getRandomValue(int max, int min = 0) const {
		return random(min, max);
	}

	/*
	 * \brief check if the the generator is valid
	 * \return a random value in the interval [min ; max[
	 */
	inline boolean isValid() {return mValidity.isValid();}
};

} /* namespace liberamox */

#endif /* LIBRARIES_LIBERAMOX_RANDOMGENERATOR_H_ */
