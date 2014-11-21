/*
 * jgmath.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: mrgame64
 */

#include "mathutils.hpp"

#ifndef PRECISE
void gen_sin_table() {
	for (int i = 0; i < SIN_COUNT; i++)
		sin_table[i] = sin((i + 0.5f) / SIN_COUNT * radFull);
	for (int i = 0; i < 360; i += 90)
		sin_table[(int)(i * degToIndex) & SIN_MASK] = sin(i * degRad);
	sin_gen = true;
};

fp pre_sin(fp rad) {
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)(rad * radToIndex) & SIN_MASK];
};

fp pre_cos(fp rad) {
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)((rad + PI / 2) * radToIndex) & SIN_MASK];
};
#endif

fp sin_deg(fp deg) {
#ifndef PRECISE
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)(deg * degToIndex) & SIN_MASK];
#endif
	return sin(deg * degRad);
};

fp cos_deg(fp deg) {
#ifndef PRECISE
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)((deg + 90) * degToIndex) & SIN_MASK];
#endif
	return cos(deg * degRad);
};
