/*
 * Matrix3.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#include "../vecmat.hpp"

using namespace math;

Matrix3::Matrix3() {
	tmp = new fp*[3];
	v = new fp*[3];

	for(int i=0; i<3; i++) {
		tmp[i] = new fp[3];
		v[i] = new fp[3];
	}
}

Matrix3::Matrix3(fp val[3][3]): Matrix3() {
	for(int x=0; x<3; x++)
		for(int y=0; y<3; y++)
			this->v[x][y] = val[x][y];
}

Matrix3::Matrix3(const Matrix3& m): Matrix3() {
	for(int x=0; x<3; x++)
		for(int y=0; y<3; y++)
			this->v[x][y] = m.v[x][y];
}

void Matrix3::swap() {
	fp** swap = tmp;
	tmp = v;
	v = swap;
}

void Matrix3::trnsp() {
	swap();

	for(int x=0; x<3; x++)
		for(int y=0; y<3; y++)
			v[y][x] = tmp[x][y];
}

inline fp Matrix3::det() {
	return  +v[0][0] * (v[1][1]*v[2][2] - v[1][2]*v[2][1])
			-v[0][1] * (v[1][0]*v[2][2] - v[1][2]*v[2][0])
			+v[0][2] * (v[1][0]*v[2][0] - v[1][1]*v[2][0]);
}

void Matrix3::inv() {
	fp det = this->det();
	if(det == 0) {	//determinant can't be zero
		throw zero_det;
		return;
	}

	tmp[0][0] = v[1][1] * v[2][2] - v[2][1] * v[1][2];
	tmp[1][0] = v[2][0] * v[1][2] - v[1][0] * v[2][2];
	tmp[2][0] = v[1][0] * v[2][1] - v[2][0] * v[1][1];
	tmp[0][1] = v[2][1] * v[0][2] - v[0][1] * v[2][2];
	tmp[1][1] = v[0][0] * v[2][2] - v[2][0] * v[0][2];
	tmp[2][1] = v[2][0] * v[0][1] - v[0][0] * v[2][1];
	tmp[0][2] = v[0][1] * v[1][2] - v[1][1] * v[0][2];
	tmp[1][2] = v[1][0] * v[0][2] - v[0][0] * v[1][2];
	tmp[2][2] = v[0][0] * v[1][1] - v[1][0] * v[0][1];

	swap();
	*this *= 1.0/det;
}

void Matrix3::set_rot(fp rad) {
	fp cos = math::cos(rad);
	fp sin = math::sin(rad);

	v[0][0] = cos;
	v[1][0] = sin;
	v[2][0] = 0;

	v[0][1] = -sin;
	v[1][1] = cos;
	v[2][1] = 0;

	v[0][2] = 0;
	v[1][2] = 0;
	v[2][2] = 1;
}

inline void Matrix3::set_rotd(fp deg) {
	set_rot(deg * degRad);
}

void Matrix3::set_rot(Vec3& axis, fp rad) {
	fp cos = math::cos(rad);
	fp sin = math::sin(rad);
	fp oc = 1.0 - cos;

	v[0][0] = oc * axis.x * axis.x + cos;
	v[1][0] = oc * axis.x * axis.y - axis.z * sin;
	v[2][0] = oc * axis.z * axis.x + axis.y * sin;
	v[0][1] = oc * axis.x * axis.y + axis.z * sin;
	v[1][1] = oc * axis.y * axis.y + cos;
	v[2][1] = oc * axis.y * axis.z - axis.x * sin;
	v[0][2] = oc * axis.z * axis.x - axis.y * sin;
	v[1][2] = oc * axis.y * axis.z + axis.x * sin;
	v[2][2] = oc * axis.z * axis.z + cos;
}

inline void Matrix3::set_rotd(Vec3& axis, fp deg) {
	set_rot(axis, deg * degRad);
}

fp Matrix3::get_rot() {
	return atan2(v[1][0], v[0][0]);
}

inline fp Matrix3::get_rotd() {
	return get_rot() * radDeg;
}

void Matrix3::set_trn(fp x, fp y) {
	v[0][0] = 1;
	v[1][0] = 0;
	v[2][0] = 0;

	v[0][1] = 0;
	v[1][1] = 1;
	v[2][1] = 0;

	v[0][2] = x;
	v[1][2] = y;
	v[2][2] = 1;
}

inline void Matrix3::set_trn(Vec2& v) {
	set_trn(v.x, v.y);
}

void Matrix3::set_scl(fp sx, fp sy) {
	v[0][0] = sx;
	v[1][0] = 0;
	v[2][0] = 0;

	v[0][1] = 0;
	v[1][1] = sy;
	v[2][1] = 0;

	v[0][2] = 0;
	v[1][2] = 0;
	v[2][2] = 1;
}

inline void Matrix3::set_scl(Vec2& v) {
	set_scl(v.x, v.y);
}

Vec2 Matrix3::get_scl() {
	return Vec2(v[0][0], v[1][1]);
}
