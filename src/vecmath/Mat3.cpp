/*
 * Mat3.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "../vecmat.hpp"

using namespace math;

Mat3::Mat3() {
	tmp = new fp[9];
	v = new fp[9];

	set_zero();
}

Mat3::Mat3(fp val[3][3]): Mat3() {
	for(int x=0; x<3; x++)
		for(int y=0; y<3; y++)
			this->v[x*3 + y] = val[y][x];
}

Mat3::Mat3(const Mat3& m): Mat3() {
	for(int i=0; i<9; i++)
		this->v[i] = m.v[i];
}

void Mat3::swap() {
	fp* swap = tmp;
	tmp = v;
	v = swap;
}

void Mat3::trnsp() {
	swap();

	v[M00] = tmp[M00];
	v[M01] = tmp[M10];
	v[M02] = tmp[M20];
	v[M10] = tmp[M01];
	v[M11] = tmp[M11];
	v[M12] = tmp[M21];
	v[M20] = tmp[M02];
	v[M21] = tmp[M12];
	v[M22] = tmp[M22];
}

inline fp Mat3::det() {
	return  +v[M00] * (v[M11]*v[M22] - v[M12]*v[M21])
			-v[M01] * (v[M10]*v[M22] - v[M12]*v[M20])
			+v[M02] * (v[M10]*v[M20] - v[M11]*v[M20]);
}

void Mat3::inv() {
	fp det = this->det();
	if(det == 0) {	//determinant can't be zero
		throw zero_det;
		return;
	}

	tmp[M00] = v[M11] * v[M22] - v[M21] * v[M12];
	tmp[M10] = v[M20] * v[M12] - v[M10] * v[M22];
	tmp[M20] = v[M10] * v[M21] - v[M20] * v[M11];
	tmp[M01] = v[M21] * v[M02] - v[M01] * v[M22];
	tmp[M11] = v[M00] * v[M22] - v[M20] * v[M02];
	tmp[M21] = v[M20] * v[M01] - v[M00] * v[M21];
	tmp[M02] = v[M01] * v[M12] - v[M11] * v[M02];
	tmp[M12] = v[M10] * v[M02] - v[M00] * v[M12];
	tmp[M22] = v[M00] * v[M11] - v[M10] * v[M01];

	swap();
	*this *= 1.0/det;
}

void Mat3::set_rot(fp rad) {
	fp cos = math::cos(rad);
	fp sin = math::sin(rad);

	v[M00] = cos;
	v[M10] = sin;
	v[M20] = 0;

	v[M01] = -sin;
	v[M11] = cos;
	v[M21] = 0;

	v[M02] = 0;
	v[M12] = 0;
	v[M22] = 1;
}

inline void Mat3::set_rotd(fp deg) {
	set_rot(deg * degRad);
}

void Mat3::set_rot(Vec3& axis, fp rad) {
	fp cos = math::cos(rad);
	fp sin = math::sin(rad);
	fp oc = 1.0 - cos;

	v[M00] = oc * axis.x * axis.x + cos;
	v[M10] = oc * axis.x * axis.y - axis.z * sin;
	v[M20] = oc * axis.z * axis.x + axis.y * sin;
	v[M01] = oc * axis.x * axis.y + axis.z * sin;
	v[M11] = oc * axis.y * axis.y + cos;
	v[M21] = oc * axis.y * axis.z - axis.x * sin;
	v[M02] = oc * axis.z * axis.x - axis.y * sin;
	v[M12] = oc * axis.y * axis.z + axis.x * sin;
	v[M22] = oc * axis.z * axis.z + cos;
}

inline void Mat3::set_rotd(Vec3& axis, fp deg) {
	set_rot(axis, deg * degRad);
}

fp Mat3::get_rot() {
	return atan2(v[M10], v[M00]);
}

inline fp Mat3::get_rotd() {
	return get_rot() * radDeg;
}

void Mat3::set_trn(fp x, fp y) {
	v[M00] = 1;
	v[M10] = 0;
	v[M20] = 0;

	v[M01] = 0;
	v[M11] = 1;
	v[M21] = 0;

	v[M02] = x;
	v[M12] = y;
	v[M22] = 1;
}

inline void Mat3::set_trn(Vec2& v) {
	set_trn(v.x, v.y);
}

void Mat3::set_scl(fp sx, fp sy) {
	v[M00] = sx;
	v[M10] = 0;
	v[M20] = 0;

	v[M02] = 0;
	v[M11] = sy;
	v[M21] = 0;

	v[M02] = 0;
	v[M12] = 0;
	v[M22] = 1;
}

inline void Mat3::set_scl(Vec2& v) {
	set_scl(v.x, v.y);
}

Vec2 Mat3::get_scl() {
	return Vec2(v[M00], v[M11]);
}
