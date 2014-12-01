/*
 * mathutils.hpp
 *
 *	lib-mathutils
 * 		A C++ math library
 *
 *  Created on: Nov 21, 2014
 *      Author: mrgame64
 *
 *	Credits go to:
 *  	- Nathan Sweet
 *  	- badlogicgames@gmail.com
 * 	From the LibGDX project for most of the Java code
 * 		&&
 * 		- golak from HeliumProject
 * 	For Vec2 operators
 */

#include <cmath>
#include "common.h"

//Defines floating point precision
#ifdef DOUBLE_T
typedef double fp;
#else
typedef float fp;
#endif

namespace math
{

	/*
	 * 		Mathematic constants
	 */

	//PI
	const fp PI = 3.14159265358979323846264338327950288419716939937510;
	const fp HALF_PI = 0.5 * PI;
	const fp TWO_PI = 2.0 * PI;
	const fp TWO_PI_INV = 1.0 / TWO_PI;
	//Degrees-radians conversion
	const fp radDeg = 180.0 / PI;
	const fp degRad = PI / 180.0;
	const fp radFull = 2 * PI;
	const fp degFull = 360.0;
	//Others
	const fp E = 2.71828182845904523536028747135266249775724709369995; //Euler's number


	/*
	 * 		Mathematic functions
	 * 		maths.cpp
	 */
	//Sine-cosine
	fp sin(fp rad);
	fp cos(fp rad);

	fp sin_deg(fp deg);
	fp cos_deg(fp deg);

	//Atan2
	fp atan2(fp y, fp x);

	//Powers&roots
	inline fp pow(fp b, fp e) { return std::pow(b, e); }
	inline fp sqrt(fp x) { return std::sqrt(x); }

	/*
	 * 		Extra-precision numbers
	 * 		xprec.hpp
	 * 		xprec.cpp
	 */
	class float128;
	class u128;
	class u256;
	class u512;

	/*
	 * 		Random number generation
	 * 		random.cpp
	 */
	void randomize_seeds();

	u64 rand_long();
	float rand_float();
	double rand_double();
	int rand_int();
	short rand_short();
	char rand_char();

	fp rand_norm();


	/*
	 * 		Cryptographic functions/algorithms
	 * 		crypto.cpp
	 */
	//CRC
	u16 crc16();
	u32 crc32();
	u64 crc64();
	//Message-Digest
	u128 md2();
	u128 md3();
	u128 md4();
	u128 md5();
	//SHA
	u256 sha256();
	//MurmurHash 3
	u32 murmurhash3_32();
	u64 murmurhash3_64();


	/*
	 * 		Limiting&interpolating numbers
	 * 		rngirp.cpp
	 */

	//Clamping
	int clamp(int x, int max, int min);
	fp clamp(fp x, fp max, fp min);
	//Checking ranges
	int is_range(int x, int max, int min);
	fp is_range(fp x, fp max, fp min);
	//Interpolating
	fp lerp(fp x, fp start, fp end);


	/*
	 * 		Rounding&comparing numbers
	 * 		round.cpp
	 */
	#define FLOAT_ROUNDING_ERROR 1e-6

	//Rounding
	inline int round(fp x) { return std::round(x); }
	inline int floor(fp x) { return std::floor(x); }
	inline int ceil(fp x) { return std::ceil(x); }
	//Comparing
	bool is_zero(fp x);
	bool is_zero(fp x, fp error);
	bool is_equal(fp x);
	bool is_equal(fp x, fp error);
	fp max(fp a, fp b);
	int max(int a, int b);
	long long max(long long a, long long b);

}

