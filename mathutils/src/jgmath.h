/*
 * jgmath.h
 *
 *  Created on: Oct 20, 2014
 *      Author: mrgame64
 */
#import <cmath>

#ifndef JGMATH_H_
#define JGMATH_H_

#ifdef DOUBLE_PREC
typedef double fp;
#else
typedef float fp;
#endif

//Constants
const fp radToDeg;
const fp degToRad;

//Functions


//Matrices


//Vectors
class Vec2 {
	public:
		fp x, y;

		Vec2();
		Vec2(Vec2 v);
		Vec2(fp x, fp y);

		Vec2 copy();

		//Operators
		Vec2&	operator= (const Vec2& v) { x = v.x; y = v.y; return *this; }
		Vec2&	operator+= (const Vec2& v) { x += v.x; y += v.y; return *this; }
		Vec2&	operator-= (const Vec2& v) { x -= v.x; y -= v.y; return *this; }
		Vec2&	operator*= (const Vec2& v) { x *= v.x; y *= v.y; return *this; }
		Vec2&	operator*= (const fp v) { x *= v; y *= v; return *this; }
		Vec2&	operator/= (const Vec2& v) { x /= v.x; y /= v.y; return *this; }
		Vec2&	operator/= (const fp v) { x /= v; y /= v; return *this; }
		Vec2	operator- () const { return Vec2( -x, -y ); }
		Vec2	operator+ (const Vec2& v) const { return Vec2 (x + v.x, y + v.y); }
		Vec2	operator- (const Vec2& v) const { return Vec2 (x - v.x, y - v.y); }
		Vec2	operator* (const Vec2& v) const { return Vec2 (x * v.x, y * v.y); }
		Vec2	operator* (const fp v) const { return Vec2 (x * v, y * v); }
		Vec2	operator/ (const Vec2& v) const { return Vec2 (x / v.x, y / v.y); }
		Vec2	operator/ (const fp v) const { return Vec2 (x / v, y / v); }
		bool	operator== (const Vec2& v) const { return (x == v.x && y == v.y); }
		bool	operator!= (const Vec2& v) const { return !(x == v.x && y == v.y); }

		void normalize();
		void limit(fp l);
		void clamp(fp min, fp max);

		fp length();
		fp lenght2();
		fp angle();
		fp dot(Vec2* v);
		fp dot(fp x, fp y);
		fp cross(Vec2& v);
		fp cross(fp x, fp y);
};


#endif /* JGMATH_H_ */
