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

#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

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
	float fast_inv_sqrt(float x);
	double fast_inv_sqrt(double x);

	fp sqrt(fp x);
	inline fp pow(fp b, fp e) { return std::pow(b, e); }

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

#endif
