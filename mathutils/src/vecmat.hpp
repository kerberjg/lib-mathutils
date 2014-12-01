/*
 * vecmath.hpp
 *
 *  Created on: Oct 20, 2014
 *      Author: James Game (mrgame64)
 */
#ifndef JGMATH_H_
#define JGMATH_H_

#include "mathutils.hpp"

using namespace math;

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

		char* to_string();
};

class Matrix4 {};

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
		/*Vec2&	operator*= (const Matrix3& m) { fp x = this->x * m.val[0] + this->y * m.val[3] + m.val[6];
												fp y = this->x * m.val[1] + this->y * m.val[4] + m.val[7];
												this->x = x;
												this->y = y;
												return *this; };*/
		Vec2&	operator/= (const Vec2& v) { x /= v.x; y /= v.y; return *this; }
		Vec2&	operator/= (const fp v) { x /= v; y /= v; return *this; }
		Vec2	operator- () const { return Vec2( -x, -y ); }
		Vec2	operator+ (const Vec2& v) const { return Vec2 (x + v.x, y + v.y); }
		Vec2	operator- (const Vec2& v) const { return Vec2 (x - v.x, y - v.y); }
		Vec2	operator* (const Vec2& v) const { return Vec2 (x * v.x, y * v.y); }
		Vec2	operator* (const fp v) const { return Vec2 (x * v, y * v); }
		/*Vec2	operator* (const Matrix3 m) { return Vec2 (	x * m.val[0] + y * m.val[3] + m.val[6],
															x * m.val[1] + y * m.val[4] + m.val[7]); };*/
		Vec2	operator/ (const Vec2& v) const { return Vec2 (x / v.x, y / v.y); }
		Vec2	operator/ (const fp v) const { return Vec2 (x / v, y / v); }
		bool	operator== (const Vec2& v) const { return (x == v.x && y == v.y); }
		bool	operator!= (const Vec2& v) const { return !(x == v.x && y == v.y); }

		//TODO: add static functions
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

		char* to_string();
};

class Vec3 {};

class Vec4 {};

#endif /* JGMATH_H_ */
