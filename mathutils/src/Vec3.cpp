/*
 * Vec3.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: mrgame64
 */

#include "vecmat.hpp"

using namespace math;

Vec3::Vec3(): x(0), y(0), z(0)  {
}

Vec3::Vec3(const Vec3& v): x(v.x), y(v.y), z(v.z){
}

Vec3::Vec3(fp x, fp y, fp z): x(x), y(y), z(z) {
}
