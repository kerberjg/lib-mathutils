/*
 * Vec2.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: mrgame64
 */

#include "jgmath.h"

Vec2::Vec2(): x(0), y(0) {
}

Vec2::Vec2(const Vec2& v) {
	Vec2* vp = v;
	x = vp->x;
	y = vp->y;
}

Vec2::Vec2(fp x, fp y): x(x), y(y) {
}

Vec2 Vec2::copy() {
	return new Vec2(x, y);
}

void Vec2::norm() {
	if(x != 0 && y != 0) {
		fp len = len();
		x /= len;
		y /= len;
	}
}

void Vec2::limit(fp l) {
	if(len2() > l*l)
		set_len(l);
}

void Vec2::clamp(fp min, fp max) {
	fp l2 = len2();
	if(l2 > max*max)
		set_len(max);
	else if(l2 < min*min)
		set_len(min);
}

void Vec2::set_angle(fp rad) {
	x = len();
	y = 0;
	rotate(rad);
}

void Vec2::set_len(fp l) {
	norm();
	this *= len;
}

void Vec2::rotate(fp rad) {
	fp cos = cos(rad);
	fp sin = sin(rad);

	fp nx = x*cos - y*sin;
	fp ny = x*sin - y*cos;

	x = nx;
	y = ny;
}

void Vec2::rotate_90(int i) {
	int ci = 0;

	ci |= ((x >= 0) ? 1 : 0);
	ci |= ((y >= 0) ? 2 : 0);

	ci = (ci + i) % 4;

	x = abs(x) * ((x >= 0) ? -1 : 1);
	y = abs(y) * ((y >= 0) ? -1 : 1);
}

void Vec2::set_zero() {
	x = y = 0;
}

fp Vec2::len() {
	return sqrt(x*x + y*y);
}

fp Vec2::len2() {
	return x*x + y*y;
}

fp Vec2::angle() {
	//TODO: see if < -2PI // > 2PI -- cases should be checked
	return atan2(y, x);
}

fp Vec2::dotp(Vec2& v) {
	Vec2 *vp = v;
	return dotp(vp->x, vp->y);
}

fp Vec2::dotp(fp x, fp y) {
	return this->x*x + this->y*y;
}

fp Vec2::cross(Vec2& v) {
	Vec2 *vp = v;
	return cross(vp->x, vp->y);
}

fp Vec2::cross(fp x, fp y) {
	return this->x*y - this->y*x;
}

fp Vec2::dist(Vec2& v) {
	Vec2 *vp = v;
	return dist(vp->x, vp->y);
}

fp Vec2::dist(fp x, fp y) {
	return sqrt(dist2(x, y));
}

fp Vec2::dist2(Vec2& v) {
	Vec2 *vp = v;
	return dist2(vp->x, vp->y);
}

fp Vec2::dist2(fp x, fp y) {
	fp dx = x - this->x;
	fp dy = y - this->y;

	return dx*dx + dy*dy;
}

void Vec2::lerp(Vec2& v, fp a) {
	Vec2 *vp = v;
	fp inv_a = 1 - a;

	x = (x * inv_a) + (vp->x * a);
	y = (y * inv_a) + (vp->y * a);
}
