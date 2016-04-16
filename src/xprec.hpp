/*
 * xprec.hpp
 *
 *	Very precise numbers
 * 		xprec.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: Jakub Kerber <kerber.jg@gmail.com>
 */

#ifndef XPREC_HPP_
#define XPREC_HPP_

#include "mathutils.hpp"

namespace math {

	//96bit floating point
	class float128 {
		public:
			u64 v;
			s64 s;

			//Constructors
			float128();
			float128(u64 value, s64 scale);

			//Operators
			float128&	operator= (const float128& r) { v = r.v; s = r.s; return *this; }
			float128&	operator+= (const float128& r) { v += r.v; s = math::max(s,r.s); return *this; }
			float128&	operator-= (const float128& r) { v -= r.v; s = math::max(s,r.s); return *this; }
			float128&	operator*= (const float128& r) { v *= r.v; s += r.s; return *this; }
			float128&	operator/= (const float128& r) { v /= r.v; s -= r.s; return *this; }
			//TODO: division of float128 to be investigated
			//source: https://docs.oracle.com/javase/1.5.0/docs/api/java/math/BigDecimal.html#divide(BigDecimal divisor)

			float128		operator+ (const float128& r) const { return float128 (v + r.v, math::max(s,r.s)); };
			float128		operator- (const float128& r) const { return float128 (v - r.v, math::max(s,r.s)); };
			float128		operator* (const float128& r) const { return float128 (v * r.v, s + r.s); };
			float128		operator/ (const float128& r) const { return float128 (v / r.v, s - r.s); };

			bool	operator== (const float128& r) {
				if(v != r.v)
					return false;
				else
					if(v == 0)
						return true;
					else
						return (s == r.s);
			};
			bool	operator!= (const float128& r) {
				if(v != r.v)
					return true;
				else
					if(v == 0)
						return false;
					else
						return (s != r.s);
			};

			//Conversion
			float128& double_to_float128(double d);
			double to_double();
			char* to_string();
	};
	//Big integers
	class u128;
	class u256;

}


#endif /* XPREC_HPP_ */
