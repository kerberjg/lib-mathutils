/*
 * rngirp.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "mathutils.hpp"

using namespace math;

int clamp(int x, int max, int min) {
	return ( x > max ? max : (x < min ? min : x));
}

fp clamp(fp x, fp max, fp min) {
	return ( x > max ? max : (x < min ? min : x));
}

bool is_range(int x, int max, int min, bool extremes) {
	if(extremes)
		return ( min <= x && x <= max );
	else
		return ( min < x && x < max);
}

bool is_range(fp x, fp max, fp min, bool extremes) {
	if(extremes)
		return ( min <= x && x <= max );
	else
		return ( min < x && x < max);
}

fp lerp(fp x, fp start, fp end) {
	return x * (end - start) + start;
}
