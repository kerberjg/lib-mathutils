/*
 * Vec2.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: mrgame64
 */

#include "vecmat.hpp"

Vec2::Vec2(): x(0), y(0) {
}

Vec2::Vec2(const Vec2& v) {
	x = v.x;
	y = v.y;
}

Vec2::Vec2(fp x, fp y): x(x), y(y) {
}

Vec2* Vec2::copy() {
	return new Vec2(x, y);
}

void Vec2::norm() {
	if(x != 0 && y != 0) {
		fp l = len();
		x /= l;
		y /= l;
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
	*this *= l;
}

void Vec2::rotate(fp rad) {
	fp c = cos(rad);
	fp s = sin(rad);

	fp nx = x*c - y*s;
	fp ny = x*s - y*c;

	x = nx;
	y = ny;
}

void Vec2::rotate_90(int i) {
	int ci = 0;

	ci |= ((x >= 0) ? 1 : 0);
	ci |= ((y >= 0) ? 2 : 0);

	ci = (ci + i) % 4;

	x = std::abs(x) * ((x >= 0) ? -1 : 1);
	y = std::abs(y) * ((y >= 0) ? -1 : 1);
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
	#ifndef PRECISE
	return pre_atan2(y, x);
	#else
	return atan2(y, x);
	#endif
}

fp Vec2::dotp(Vec2& v) {
	return dotp(v.x, v.y);
}

fp Vec2::dotp(fp x, fp y) {
	return this->x*x + this->y*y;
}

fp Vec2::cross(Vec2& v) {
	return cross(v.x, v.y);
}

fp Vec2::cross(fp x, fp y) {
	return this->x*y - this->y*x;
}

fp Vec2::dist(Vec2& v) {
	return dist(v.x, v.y);
}

fp Vec2::dist(fp x, fp y) {
	return sqrt(dist2(x, y));
}

fp Vec2::dist2(Vec2& v) {
	return dist2(v.x, v.y);
}

fp Vec2::dist2(fp x, fp y) {
	fp dx = x - this->x;
	fp dy = y - this->y;

	return dx*dx + dy*dy;
}

void Vec2::lerp(Vec2& v, fp a) {
	fp inv_a = 1 - a;

	x = (x * inv_a) + (v.x * a);
	y = (y * inv_a) + (v.y * a);
}

bool Vec2::epsilon_equals(Vec2& v, fp epsilon) {
	return epsilon_equals(v.x, v.y, epsilon);
}

bool Vec2::epsilon_equals(fp x, fp y, fp epsilon) {
	return ((this->x - x) <= epsilon) && ((this->y - y) <= epsilon);
}

bool Vec2::is_zero() {
	return (x == 0 && y ==0);
}

