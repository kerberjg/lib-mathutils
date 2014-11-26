/*
 * xprec.hpp
 *
 *	Very precise numbers
 * 		xprec.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: mrgame64
 */

#ifndef XPREC_HPP_
#define XPREC_HPP_

#include "mathutils.hpp"

//96bit floating point
class f96 {
	public:
		u64 v;
		s32 s;

		//Constructors
		f96();
		f96(u64 value, s32 scale);

		//Operators
		f96&	operator= (const f96& r) { v = r.v; s = r.s; return *this; }
		f96&	operator+= (const f96& r) { v += r.v; s = max(s,r.s); return *this; }
		f96&	operator-= (const f96& r) { v -= r.v; s = max(s,r.s); return *this; }
		f96&	operator*= (const f96& r) { v *= r.v; s += r.s; return *this; }
		f96&	operator/= (const f96& r) { v /= r.v; s -= r.s; return *this; }
		//TODO: division of f96 to be investigated
		//source: https://docs.oracle.com/javase/1.5.0/docs/api/java/math/BigDecimal.html#divide(BigDecimal divisor)

		f96		operator+ (const f96& r) const { return f96 (v + r.v, max(s,r.s)); };
		f96		operator- (const f96& r) const { return f96 (v - r.v, max(s,r.s)); };
		f96		operator* (const f96& r) const { return f96 (v * r.v, s + r.s); };
		f96		operator/ (const f96& r) const { return f96 (v / r.v, s - r.s); };

		bool	operator== (const f96& r) {
			if(v != r.v)
				return false;
			else
				if(v == 0)
					return true;
				else
					return (s == r.s);
		};
		bool	operator!= (const f96& r) {
			if(v != r.v)
				return true;
			else
				if(v == 0)
					return false;
				else
					return (s != r.s);
		};

		//Conversion
		f96& double_to_f96(double d);
		double to_double();
		char* to_string();
};
//Big integers
class u128;
class u256;




#endif /* XPREC_HPP_ */
