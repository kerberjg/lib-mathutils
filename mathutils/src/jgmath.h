/*
 * jgmath.h
 *
 * lib-mathutils
 * 		A C++ math library
 *
 *  Created on: Oct 20, 2014
 *      Author: James Game (mrgame64)
 *
 *  Credits go to:
 *  	- Nathan Sweet
 *  	- badlogicgames@gmail.com
 * 	From the LibGDX project for most of the Java code
 * 		&&
 * 		- golak from HeliumProject
 * 	For Vec2 operators
 */
#ifndef JGMATH_H_
#define JGMATH_H_

#include <cmath>

//Defines floating point precision
#ifdef DOUBLE_PREC
typedef double fp;
#else
typedef float fp;
#endif

#ifndef PRECISE
//Sine default precision bits
#ifndef SIN_BITS
#define SIN_BITS 16
#endif
#define SIN_MASK (~(-1 << SIN_BITS))
#define SIN_COUNT (SIN_MASK + 1)
#endif

//Constants
const fp PI = 3.14159265358979323846264338327950288419716939937510;
const fp HALF_PI = 0.5 * PI;
const fp TWO_PI = 2.0 * PI;
const fp TWO_PI_INV = 1.0 / TWO_PI;

const fp radDeg = 180.0 / PI;
const fp degRad = PI / 180.0;
const fp radFull = 2 * PI;
const fp degFull = 360.0;
#ifndef PRECISE
const fp radToIndex = SIN_COUNT / radFull;
const fp degToIndex = SIN_COUNT / degFull;

//Functions
fp sin_table[SIN_COUNT];
bool sin_gen = false;

void gen_sin_table() {
	for (int i = 0; i < SIN_COUNT; i++)
		sin_table[i] = sin((i + 0.5f) / SIN_COUNT * radFull);
	for (int i = 0; i < 360; i += 90)
		sin_table[(int)(i * degToIndex) & SIN_MASK] = sin(i * degRad);
	sin_gen = true;
};
#endif

#ifndef PRECISE
fp sin(fp rad) {
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)(rad * radToIndex) & SIN_MASK];
};

fp cos(fp rad) {
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)((rad + PI / 2) * radToIndex) & SIN_MASK];
};
#endif

fp sin_deg(fp deg) {
#ifndef PRECISE
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)(deg * degToIndex) & SIN_MASK];
#endif
	return sin(deg * degRad);
};

fp cos_deg(fp deg) {
#ifndef PRECISE
	if(!sin_gen)
		gen_sin_table();
	return sin_table[(int)((deg + 90) * degToIndex) & SIN_MASK];
#endif
	return cos(deg * degRad);
};

//Matrices
class Matrix3 {
	public:
		static const int M00 = 0;
		static const int M01 = 3;
		static const int M02 = 6;
		static const int M10 = 1;
		static const int M11 = 4;
		static const int M12 = 7;
		static const int M20 = 2;
		static const int M21 = 5;
		static const int M22 = 8;

		fp val[9];
		fp tmp[9];
};

//Vectors
class Vec2 {
	public:
		fp x, y;

		Vec2();
		Vec2(const Vec2& v);
		Vec2(fp x, fp y);

		Vec2 copy();

		//Operators
		Vec2&	operator= (const Vec2& v) { x = v.x; y = v.y; return *this; }
		Vec2&	operator+= (const Vec2& v) { x += v.x; y += v.y; return *this; }
		Vec2&	operator-= (const Vec2& v) { x -= v.x; y -= v.y; return *this; }
		Vec2&	operator*= (const Vec2& v) { x *= v.x; y *= v.y; return *this; }
		Vec2&	operator*= (const fp v) { x *= v; y *= v; return *this; }
		Vec2&	operator*= (const Matrix3& m) { ; return *this; }; //TODO: code Matrix3 operators
		Vec2&	operator/= (const Vec2& v) { x /= v.x; y /= v.y; return *this; }
		Vec2&	operator/= (const fp v) { x /= v; y /= v; return *this; }
		Vec2	operator- () const { return Vec2( -x, -y ); }
		Vec2	operator+ (const Vec2& v) const { return Vec2 (x + v.x, y + v.y); }
		Vec2	operator- (const Vec2& v) const { return Vec2 (x - v.x, y - v.y); }
		Vec2	operator* (const Vec2& v) const { return Vec2 (x * v.x, y * v.y); }
		Vec2	operator* (const fp v) const { return Vec2 (x * v, y * v); }
		Vec2	operator* (const Matrix3 m) { return Vec2 (); }; //TODO: code Matrix3 operators
		Vec2	operator/ (const Vec2& v) const { return Vec2 (x / v.x, y / v.y); }
		Vec2	operator/ (const fp v) const { return Vec2 (x / v, y / v); }
		bool	operator== (const Vec2& v) const { return (x == v.x && y == v.y); }
		bool	operator!= (const Vec2& v) const { return !(x == v.x && y == v.y); }

		void norm();
		void limit(fp l);
		void clamp(fp min, fp max);
		void set_angle(fp rad);
		void rotate(fp rad);
		void rotate_90(int i);
		void set_zero();

		fp len();
		fp len2();
		fp angle();
		fp dotp(Vec2& v);
		fp dotp(fp x, fp y);
		fp cross(Vec2& v);
		fp cross(fp x, fp y);
		fp dist(Vec2& v);
		fp dist(fp x, fp y);
		fp dist2(Vec2& v);
		fp dist2(fp x, fp y);

		Vec2 lerp(Vec2& v, fp alpha);

		bool epsilon_equals(Vec2& v, fp epsilon);
		bool epsilon_equals(fp x, fp y, fp epsilon);
		bool is_zero();
};

#endif /* JGMATH_H_ */
