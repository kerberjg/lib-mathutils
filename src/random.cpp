/*
 * random.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "xprec.hpp"
#include "stdlib.h"
#include <climits>

using namespace math;

/*	xorshift128+ algorithm
 *	Credit to: Sebastiano Vigna (vigna@acm.org)
 *	Released under Creative Commons Public License v1.0 (http://creativecommons.org/publicdomain/zero/1.0/)
 *	http://xorshift.di.unimi.it/
 *
 *	Implementation by James Game (Jakub Kerber <kerber.jg@gmail.com>)
 */

const double NORM_FLOAT = 1.0 / (1L << 24);
const double NORM_DOUBL = 1.0 / (1L << 53);

u64 r_seed0, r_seed1;

void math::randomize_seeds() {
	r_seed0 = rand();
	r_seed0 = (r_seed0 << 32) | rand();
	r_seed1 = rand();
	r_seed1 = (r_seed1 << 32) | rand();
}

u64 math::rand_long() {
	if(r_seed0 == 0 || r_seed1 == 0)
		randomize_seeds();

	u64 s1 = r_seed0;
	u64 s0 = r_seed1;
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
	return (rand_long() >> 11) * NORM_DOUBL;
}

float math::rand_float() {
	return (rand_long() >> 40) * NORM_FLOAT;
}

double math::rand_gauss(double mean, double stdd) {

}

double math::rand_invgauss(double mean, double std) {

}
