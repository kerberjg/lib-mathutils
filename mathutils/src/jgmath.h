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

#define PRECISE
//Defines floating point precision
#ifdef DOUBLE_T
typedef double fp;
#else
typedef float fp;
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


//Functions
#ifndef PRECISE
//Sine default precision bits
#ifndef SIN_BITS
#define SIN_BITS 16
#endif
#define SIN_MASK (~(-1 << SIN_BITS))
#define SIN_COUNT (SIN_MASK + 1)
const fp radToIndex = SIN_COUNT / radFull;
const fp degToIndex = SIN_COUNT / degFull;

extern fp sin_table[SIN_COUNT];
extern bool sin_gen;

void gen_sin_table();
fp pre_sin(fp rad);
fp pre_cos(fp rad);
#endif

fp sin_deg(fp deg);
fp cos_deg(fp deg);

//Atan
#ifndef PRECISE
#define ATAN2_BITS = 8; // Adjust for accuracy.
#define ATAN2_BITS2 = ATAN2_BITS << 1;
#define ATAN2_MASK = ~(-1 << ATAN2_BITS2);
#define ATAN2_COUNT = ATAN2_MASK + 1;
#define ATAN2_DIM = (int)Math.sqrt(ATAN2_COUNT);
#define INV_ATAN2_DIM_MINUS_1 = 1.0f / (ATAN2_DIM - 1);

extern fp atan2_table[ATAN2_COUNT];
extern bool atan2_gen;

void get_atan2_table();
fp pre_atan2(fp y, fp x);
#endif


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

		Vec2* copy();

		//Operators
		Vec2&	operator= (const Vec2& v) { x = v.x; y = v.y; return *this; }
		Vec2&	operator+= (const Vec2& v) { x += v.x; y += v.y; return *this; }
		Vec2&	operator-= (const Vec2& v) { x -= v.x; y -= v.y; return *this; }
		Vec2&	operator*= (const Vec2& v) { x *= v.x; y *= v.y; return *this; }
		Vec2&	operator*= (const fp v) { x *= v; y *= v; return *this; }
		Vec2&	operator*= (const Matrix3& m) { fp x = this->x * m.val[0] + this->y * m.val[3] + m.val[6];
												fp y = this->x * m.val[1] + this->y * m.val[4] + m.val[7];
												this->x = x;
												this->y = y;
												return *this; };
		Vec2&	operator/= (const Vec2& v) { x /= v.x; y /= v.y; return *this; }
		Vec2&	operator/= (const fp v) { x /= v; y /= v; return *this; }
		Vec2	operator- () const { return Vec2( -x, -y ); }
		Vec2	operator+ (const Vec2& v) const { return Vec2 (x + v.x, y + v.y); }
		Vec2	operator- (const Vec2& v) const { return Vec2 (x - v.x, y - v.y); }
		Vec2	operator* (const Vec2& v) const { return Vec2 (x * v.x, y * v.y); }
		Vec2	operator* (const fp v) const { return Vec2 (x * v, y * v); }
		Vec2	operator* (const Matrix3 m) { return Vec2 (	x * m.val[0] + y * m.val[3] + m.val[6],
															x * m.val[1] + y * m.val[4] + m.val[7]); };
		Vec2	operator/ (const Vec2& v) const { return Vec2 (x / v.x, y / v.y); }
		Vec2	operator/ (const fp v) const { return Vec2 (x / v, y / v); }
		bool	operator== (const Vec2& v) const { return (x == v.x && y == v.y); }
		bool	operator!= (const Vec2& v) const { return !(x == v.x && y == v.y); }

		void norm();
		void limit(fp l);
		void clamp(fp min, fp max);
		void set_angle(fp rad);
		void set_len(fp l);
		void rotate(fp rad);
		void rotate_90(int i);
		inline void set_zero();

		inline fp len();
		inline fp len2();
		inline fp angle();
		inline fp dotp(Vec2& v);
		inline fp dotp(fp x, fp y);
		inline fp cross(Vec2& v);
		inline fp cross(fp x, fp y);
		inline fp dist(Vec2& v);
		inline fp dist(fp x, fp y);
		inline fp dist2(Vec2& v);
		inline fp dist2(fp x, fp y);

		void lerp(Vec2& v, fp alpha);

		inline bool epsilon_equals(Vec2& v, fp epsilon);
		inline bool epsilon_equals(fp x, fp y, fp epsilon);
		inline bool is_zero();
};

#endif /* JGMATH_H_ */
