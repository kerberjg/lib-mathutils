/*
 * mathutils.hpp
 *
 *  Created on: Nov 21, 2014
 *      Author: mrgame64
 */

#include <cmath>
#include "common.h"

//Defines floating point precision
#ifdef DOUBLE_T
typedef double fp;
#else
typedef float fp;
#endif

//Constants
const fp PI = 3.14159265358979323846264338327950288419716939937510;
const fp HALF_PI = 0.5 * PI;
const fp TWO_PI = 2.0 * PI;
const fp TWO_PI_INV = 1.0 / TWO_PI;

const fp radDeg = 180.0 / PI;
const fp degRad = PI / 180.0;
const fp radFull = 2 * PI;
const fp degFull = 360.0;


//Functions
#ifndef PRECISE
//Sine default precision bits
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

//Atan
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

//Random numbers
extern long r_seed0, r_seed1;
void randomize_seeds();

long rand_long();
float rand_float();
double rand_double();
int rand_int();
short rand_short();
char rand_char();

fp rand_norm();

//MurmurHash3
extern u64 m64;
extern u32 m32;
u64 murmurhash3_64();
u32 murmurhash3_32();
