/*
 * maths.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "mathutils.hpp"

using namespace math;

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
