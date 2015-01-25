/*
 * vecmath.hpp
 *
 *  Created on: Oct 20, 2014
 *      Author: James Game (mrgame64)
 */
#ifndef JGMATH_H_
#define JGMATH_H_

#include "mathutils.hpp"

namespace math {

	enum matrix_exceptions {
		zero_det = 10
	};

	class Vec2;
	class Vec3;


	//Matrices
	class Matrix3 {
		/*
		 * (i,j) => (y,x)
		 *
		 * [ 0,0 0,1 0,2 ]
		 * [			 ]
		 * [ 1,0 1,1 2,1 ]
		 * [			 ]
		 * [ 2,0 2,1 2,2 ]
		 *
		 */

		private:
			/**Temporary matrix*/
			fp** tmp;
			/**Swaps temporary and matrix arrays*/
			void swap();

		public:
			/**The matrix itself*/
			fp** v;

			Matrix3();
			Matrix3(fp val[3][3]);
			Matrix3(const Matrix3& m);

			/**Copies the matrix to a new instance*/
			inline Matrix3 copy() { return Matrix3(*this); }

			//Operators
			Matrix3& operator= (const Matrix3& m) {
				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							v[x][y] = m.v[x][y];
				return *this;
			}
			Matrix3& operator+= (const Matrix3& m) {
				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							v[x][y] += m.v[x][y];
				return *this;
			}
			Matrix3& operator-= (const Matrix3& m) {
				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							v[x][y] -= m.v[x][y];
				return *this;
			}
			Matrix3& operator*= (const Matrix3& m) {
				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							this->v[x][y] *= v[y][x];
				return *this;
			}
			Matrix3& operator*= (const fp s) {
				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							v[x][y] *= s;
				return *this;
			}
			Matrix3& operator/= (const Matrix3& m) {
				for(int x=0; x<3; x++)
					for(int y=0; y<3; y++)
						v[x][y] /= m.v[y][x];
				return *this;
			}
			Matrix3& operator/= (const fp s) {
				for(int x=0; x<3; x++)
					for(int y=0; y<3; y++)
						v[x][y] /= s;
				return *this;
			}

			Matrix3& operator+ (const Matrix3& m) {
				Matrix3* n = new Matrix3();

				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							n->v[x][y] = v[x][y] + m.v[x][y];
				return *n;
			}
			Matrix3& operator- (const Matrix3& m) {
				Matrix3* n = new Matrix3();

				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							n->v[x][y] = v[x][y] - m.v[x][y];
				return *n;
			}
			Matrix3& operator- () {
				Matrix3* n = new Matrix3();
				for(int x=0; x<3; x++)
					for(int y=0; y<3; y++)
						n->v[x][y] = -v[x][y];
				return *n;
			}
			Matrix3& operator* (const Matrix3& m) {
				Matrix3* n = new Matrix3();

				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							n->v[x][y] = v[x][y] * m.v[y][x];
				return *n;
			}
			Matrix3& operator* (const fp s) {
				Matrix3* n = new Matrix3();

				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							n->v[x][y] = v[x][y] * s;
				return *n;
			}
			Matrix3& operator/ (const Matrix3& m) {
				Matrix3* n = new Matrix3();

				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							n->v[x][y] = v[x][y] / m.v[y][x];
				return *n;
			}
			Matrix3& operator/ (const fp s) {
				Matrix3* n = new Matrix3();

				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							n->v[x][y] = v[x][y] / s;
				return *n;
			}

			bool operator== (const Matrix3& m) {
				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							if(v[x][y] != m.v[x][y])
								return false;
				return true;
			}
			bool operator!= (const Matrix3& m) {
				for(int x=0; x<3; x++)
						for(int y=0; y<3; y++)
							if(v[x][y] != m.v[x][y])
								return true;
				return false;
			}

			/**Transposes the matrix*/
			void trnsp();
			/**Inverts the matrix*/
			void inv();
			/**Sets the matrix to the identity matrix*/
			void idt();
			/**Calculates the determinant of the matrix*/
			fp det();

			//Utils
			/**Set the matrix to a rotation matrix given a rotation angle*/
			void set_rot(fp rad);
			/**Set the matrix to a rotation matrix given a rotation angle in degrees*/
			void set_rotd(fp deg);
			/**Set the matrix to a rotation matrix given a rotation axis and angle*/
			void set_rot(Vec3& axis, fp rad);
			/**Set the matrix to a rotation matrix given a rotation axis and angle in degrees*/
			void set_rotd(Vec3& axis, fp deg);
			/**Given the matrix is a rotation matrix, returns the rotation angle*/
			fp get_rot();
			/**Given the matrix is a rotation matrix, returns the rotation angle in degrees*/
			fp get_rotd();

			/**Sets the matrix to a translation matrix given translation coordinates*/
			void set_trn(fp x, fp y);
			/**Sets the matrix to a translation matrix given a translation vector*/
			void set_trn(Vec2& v);
			/**Given the matrix is a translation matrix, returns the translation vector*/
			Vec2 get_trn();

			/**Sets the matrix to a scaling matrix given scale factors*/
			void set_scl(fp sx, fp sy);
			/**Sets the matrix to a scaling matrix given a scaling vector*/
			void set_scl(Vec2& sv);
			/**Given the matrix is a scaling matrix, returns the scaling vector*/
			Vec2 get_scl();
	};

	class Matrix4 {};

	//Vectors
	class Vec2 {
		public:
			fp x, y;

			Vec2();
			Vec2(const Vec2& v);
			Vec2(fp x, fp y);

			inline Vec2* copy() { return new Vec2(*this); }

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
																x * m.val[1] + y * m.val[4] + m.v[7]); };*/
			Vec2	operator/ (const Vec2& v) const { return Vec2 (x / v.x, y / v.y); }
			Vec2	operator/ (const fp v) const { return Vec2 (x / v, y / v); }

			bool	operator== (const Vec2& v) const { return (x == v.x && y == v.y); }
			bool	operator!= (const Vec2& v) const { return !(x == v.x && y == v.y); }
			bool	operator> (const Vec2& v) const { return ((x*x + y*y) > (v.x*v.x + v.y*v.y)); }
			bool	operator< (const Vec2& v) const { return ((x*x + y*y) < (v.x*v.x + v.y*v.y)); }
			bool	operator>= (const Vec2& v) const { return ((x*x + y*y) >= (v.x*v.x + v.y*v.y)); }
			bool	operator<= (const Vec2& v) const { return ((x*x + y*y) <= (v.x*v.x + v.y*v.y)); }

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

	class Vec3 {
		public:
			fp x, y, z;

			Vec3();
			Vec3(const Vec3& v);
			Vec3(fp x, fp y, fp z);

			inline Vec3* copy() { return new Vec3(*this); }

			//Operators
			Vec3&	operator= (const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
			Vec3&	operator+= (const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
			Vec3&	operator-= (const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
			Vec3&	operator*= (const Vec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
			Vec3&	operator*= (const fp v) { x *= v; y *= v; z *= v; return *this; }
			/*Vec3&	operator*= (const Matrix3& m) { fp x = this->x * m.val[0] + this->y * m.val[3] + m.val[6];
													fp y = this->x * m.val[1] + this->y * m.val[4] + m.val[7];
													this->x = x;
													this->y = y;
													return *this; };*/
			Vec3&	operator/= (const Vec3& v) { x /= v.x; y /= v.y; z *= v.z; return *this; }
			Vec3&	operator/= (const fp v) { x /= v; y /= v; z /= v; return *this; }
			Vec3	operator- () const { return Vec3( -x, -y, -z ); }
			Vec3	operator+ (const Vec3& v) const { return Vec3 (x + v.x, y + v.y, z + v.z); }
			Vec3	operator- (const Vec3& v) const { return Vec3 (x - v.x, y - v.y, z - v.z); }
			Vec3	operator* (const Vec3& v) const { return Vec3 (x * v.x, y * v.y, z * v.z); }
			Vec3	operator* (const fp v) const { return Vec3 (x * v, y * v, z * v); }
			/*Vec3	operator* (const Matrix3 m) { return Vec3 (	x * m.val[0] + y * m.val[3] + m.val[6],
																x * m.val[1] + y * m.val[4] + m.v[7]); };*/
			Vec3	operator/ (const Vec3& v) const { return Vec3 (x / v.x, y / v.y, z / v.z); }
			Vec3	operator/ (const fp v) const { return Vec3 (x / v, y / v, z / v); }
			bool	operator== (const Vec3& v) const { return (x == v.x && y == v.y && z == v.z); }
			bool	operator!= (const Vec3& v) const { return !(x == v.x && y == v.y && z == v.z); }

			//Modifiers
			void norm();
			void limit(fp l);
			void clamp(fp min, fp max);
			void set_angle();
			void set_len(fp l);
			void rotate();

			fp len();
			fp len2();

			//Interpolation

			//Comparing

			//String conversion
	};

	class Vec4 {};
}

#endif /* JGMATH_H_ */
