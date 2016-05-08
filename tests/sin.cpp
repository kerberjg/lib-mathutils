/*
 * sin.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */



//#define PRECISE
#define DEBUG

#include <iostream>
#include <chrono>
#include "../src/mathutils.hpp"

using namespace math;

unsigned long getMillis() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

int main() {
	int n = 10000000;
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

	std::cout << n << " elements" << std::endl << std::endl;
	std::cout << "Rounding errors:" << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Avg: " << avg << std::endl;
	std::cout << "Min: " << min << std::endl;
	std::cout << "Precision: " << 100 - (avg / TWO_PI)*100 << "%" << std::endl;

	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::duration<float> fsec;


	fp y;

	auto t0 = Time::now();
	for(fp x = 0; x < TWO_PI; x += step) {
		y = std::sin(x);
	}
	auto t1 = Time::now();
	fsec s1 = t1 - t0;

	t0 = Time::now();
	for(fp x = 0; x < TWO_PI; x += step) {
		y = math::sin(x);
	}
	t1 = Time::now();
	fsec s2 = t1 - t0;

	//ms d = std::chrono::duration_cast<ms>(fs);

	std::cout << std::endl << "Total time:" << std::endl;
	std::cout << "std: " << std::chrono::duration_cast<ms>(s1).count() << " ms" << std::endl;
	std::cout << "math: " << std::chrono::duration_cast<ms>(s2).count() << " ms" << std::endl;

	return 0;
}

