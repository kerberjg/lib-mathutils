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
#ifndef PRECISE
#ifndef SIN_BITS
#define SIN_BITS 16
#endif
#define SIN_MASK (~(-1 << SIN_BITS))
#define SIN_COUNT (SIN_MASK + 1)
const fp radToIndex = SIN_COUNT / radFull;
const fp degToIndex = SIN_COUNT / degFull;

extern fp sin_table[SIN_COUNT];
extern bool sin_gen;

void gen_sin_table();
fp pre_sin(fp rad);
fp pre_cos(fp rad);
#endif

fp sin_deg(fp deg);
fp cos_deg(fp deg);

//Atan2
#ifndef PRECISE
#define ATAN2_BITS 8 // Adjust for accuracy.
#define ATAN2_BITS2 ATAN2_BITS << 1
#define ATAN2_MASK ~(-1 << ATAN2_BITS2)
#define ATAN2_COUNT ATAN2_MASK + 1
#define ATAN2_DIM (int)Math.sqrt(ATAN2_COUNT)
#define INV_ATAN2_DIM_MINUS_1 1.0f / (ATAN2_DIM - 1)

extern fp atan2_table[ATAN2_COUNT];
extern bool atan2_gen;

void get_atan2_table();
fp pre_atan2(fp y, fp x);
#endif

/*
 * 		Random number generation
 * 		random.cpp
 */
extern long r_seed0, r_seed1;
void randomize_seeds();

long rand_long();
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
extern u64 m64;
extern u32 m32;
u64 murmurhash3_64();
u32 murmurhash3_32();


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
int round(fp x);
int floor(fp x);
int ceil(fp x);
//Comparing
bool is_zero(fp x);
bool is_zero(fp x, fp error);
bool is_equal(fp x);
bool is_equal(fp x, fp error);

/*
 * 		Very precise numbers
 * 		xprec.hpp
 */
class BigFloat;
class u128;
class u256;
