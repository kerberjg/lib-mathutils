/*
 * Vec3.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "../vecmat.hpp"

using namespace math;

Vec3::Vec3(): x(0), y(0), z(0)  {
}

Vec3::Vec3(const Vec3& v): x(v.x), y(v.y), z(v.z){
}

Vec3::Vec3(fp x, fp y, fp z): x(x), y(y), z(z) {
}

void Vec3::norm() {
	if(x == 0 && y == 0 && z == 0)
		return;

	fp l = len();
	x /= l;
	y /= l;
	z /= l;
}


fp Vec3::len() {
	return sqrt(x*x + y*y + z*z);
}

fp Vec3::len2() {
	return x*x + y*y + z*z;
}
