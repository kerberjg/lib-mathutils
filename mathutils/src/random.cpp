/*
 * random.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: mrgame64
 */

#include "mathutils.hpp"
#include "stdlib.h"
#include <climits>

using namespace math;

/*	xorshift128+ algorithm
 *	Credit to: Sebastiano Vigna (vigna@acm.org)
 *	Released under Creative Commons Public License v1.0 (http://creativecommons.org/publicdomain/zero/1.0/)
 *	http://xorshift.di.unimi.it/
 *
 *	Implementation by James Game (mrgame64)
 */

long r_seed0, r_seed1;

void math::randomize_seeds() {
	r_seed0 = rand() | (rand() << 32);
	r_seed1 = rand() | (rand() << 32);
}

long math::rand_long() {
	if(r_seed0 == 0 || r_seed1 == 0)
		randomize_seeds();

	long s1 = r_seed0;
	long s0 = r_seed1;
	r_seed0 = s0;
	s1 ^= s1 << 23; // a
	return ( r_seed1 = ( s1 ^ s0 ^ ( s1 >> 17 ) ^ ( s0 >> 26 ) ) ) + s0; // b, c
}

int math::rand_int() {
	return (int)rand_long();
}

short math::rand_short() {
	return (short)rand_long();
}

char math::rand_char() {
	return (char)rand_long();
}

double math::rand_double() {
	return (double)rand_long()/LONG_MAX;
}

float math::rand_float() {
	return (float)rand_long()/LONG_MAX;
}
