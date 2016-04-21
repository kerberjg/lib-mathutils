/*
 * sin.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: mrgame64
 */



//#define PRECISE

#include <iostream>
#include "../src/mathutils.hpp"

using namespace math;

int main() {
	int n = 10000;
	fp step = TWO_PI / n;

	fp min = TWO_PI;
	fp max = 0;
	fp avg = 0;

	for(fp x = 0; x < TWO_PI; x += step) {
		fp fast = math::sin(x);
		fp prec = std::sin(x);

		fp diff = math::abs( fast - prec );

		if(diff < min)
			min = diff;

		if(diff > max)
			max = diff;

		avg += diff;
	}

	avg /= n;

	std::cout << "Max: " << max << std::endl;
	std::cout << "Avg: " << avg << std::endl;
	std::cout << "Min: " << min << std::endl;

	return 0;
}

