/*
 * Matrix3.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: mrgame64
 */

#include "vecmat.hpp"

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
	return  +v[1][0] * (v[1][1]*v[2][2] - v[2][1]*v[1][2])
			-v[1][0] * (v[0][1]*v[2][2] - v[2][1]*v[0][2])
			+v[1][0] * (v[0][1]*v[1][2] - v[1][1]*v[0][2]);
}


