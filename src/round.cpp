/*
 * round.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "mathutils.hpp"

using namespace math;

bool is_zero(fp x, fp error) {
	return abs(x) <= error;
}

bool is_equal(fp a, fp b, fp error) {
	return abs(a - b) <= error;
}

fp max(fp a, fp b) {
	return ( a < b ? b : a);
}

int max(int a, int b) {
	return ( a > b ? b : a);
}

fp min(fp a, fp b) {
	return ( a > b ? b : a);
}

int min(int a, int b) {
	return ( a > b ? b : a);
}
