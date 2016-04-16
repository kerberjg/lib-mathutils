/*
 * maths.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "mathutils.hpp"

using namespace math;

#ifndef PRECISE
#ifndef SIN_BITS
#define SIN_BITS 16
#endif
#define SIN_MASK (~(-1 << SIN_BITS))
#define SIN_COUNT (SIN_MASK + 1)
const fp radToIndex = SIN_COUNT / radFull;
const fp degToIndex = SIN_COUNT / degFull;

fp sin_table[SIN_COUNT];
bool sin_gen;


void gen_sin_table() {
	for (int i = 0; i < SIN_COUNT; i++)
		sin_table[i] = std::sin((i + 0.5f) / SIN_COUNT * radFull);
	for (int i = 0; i < 360; i += 90)
		sin_table[(int)(i * degToIndex) & SIN_MASK] = std::sin(i * degRad);
	sin_gen = true;
};
#endif

fp math::sin(fp rad) {
#ifndef PRECISE
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)(rad * radToIndex) & SIN_MASK];
#else
	return std::sin(rad);
#endif
};

fp math::cos(fp rad) {
#ifndef PRECISE
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)((rad + PI / 2) * radToIndex) & SIN_MASK];
#else
	return std::cos(rad);
#endif
};


#ifndef PRECISE
#ifndef ATAN2_BITS
#define ATAN2_BITS 8 // Adjust for accuracy.
#endif
#define ATAN2_BITS2 ATAN2_BITS << 1
#define ATAN2_MASK ~(-1 << ATAN2_BITS2)
#define ATAN2_COUNT ATAN2_MASK + 1
#define ATAN2_DIM (int)math::sqrt(ATAN2_COUNT)
#define INV_ATAN2_DIM_MINUS_1 1.0f / (ATAN2_DIM - 1)

fp atan2_table[ATAN2_COUNT];
bool atan2_gen;

void gen_atan2_table() {
	for (int i = 0; i < ATAN2_DIM; i++) {
		for (int j = 0; j < ATAN2_DIM; j++) {
			fp x0 = i / ATAN2_DIM;
			fp y0 = j / ATAN2_DIM;
			atan2_table[j * ATAN2_DIM + i] = std::atan2(y0, x0);
		}
	}
}
#endif

fp math::atan2(fp y, fp x) {
#ifndef PRECISE
	fp add, mul;
	if (x < 0) {
		if (y < 0) {
			y = -y;
			mul = 1;
		} else
			mul = -1;
			x = -x;
			add = -PI;
		} else {
			if (y < 0) {
				y = -y;
				mul = -1;
			} else
				mul = 1;
			add = 0;
		}
		fp invDiv = 1 / ((x < y ? y : x) * INV_ATAN2_DIM_MINUS_1);

		if (!std::isfinite(invDiv)) return (std::atan2(y, x) + add) * mul;

		int xi = (int)(x * invDiv);
		int yi = (int)(y * invDiv);
		return (atan2_table[yi * ATAN2_DIM + xi] + add) * mul;
#else
	return std::atan2(y, x);
#endif
}

#define MAGICAL_NUMBER_32 (s32) 0x5f3759df //0x5f37642f (could it be? run tests) //also 0x5f375a86
#define MAGICAL_NUMBER_64 (s64) 0x5fe6ec85e7de30da //0x5fe6eb50c7b537a9 (run tests as well)

float math::fast_inv_sqrt(float x) {
	s32 i;
	float x2;

	x2 = x * 0.5;
	i  = * ( s32 * ) &x;                       // evil floating point bit level hacking
	i  = MAGICAL_NUMBER_32 - ( i >> 1 );               // what the fuck?
	x  = * ( float * ) &i;
	x *= ( 1.5 - ( x2 * x * x ) );   // 1st iteration
#ifdef PRECISE
	x *= ( 1.5 - ( x2 * x * x ) );   // 2nd iteration, this can be removed
#endif
	return x;
}

double math::fast_inv_sqrt(double x) {
	s64 i;
	double x2;

	x2 = x * 0.5;
	i  = * ( s32 * ) &x;                       // evil floating point bit level hacking
	i  = MAGICAL_NUMBER_64 - ( i >> 1 );               // what the fuck?
	x  = * ( double * ) &i;
	x  *= ( 1.5 - ( x2 * x * x ) );   // 1st iteration
#ifdef PRECISE
	x *= ( 1.5 - ( x2 * x * x ) );   // 2nd iteration, this can be removed
#endif
	return x;
}
