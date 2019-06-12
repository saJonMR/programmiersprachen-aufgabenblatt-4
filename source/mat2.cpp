#include "mat2.hpp"

#include <math.h>



Mat2 make_rotation_mat2(float phi){		//Aufgabe 2.6
	Mat2 e;
	e.e_00 = cos(phi);
	e.e_10 = -sin(phi);
	e.e_01 = sin(phi);
	e.e_11 = cos(phi);
	return e;
	}
Mat2 inverse (Mat2 const& m){
	float x = 1/ (m.e_11 * m.e_00 - m.e_10 * m.e_01);
	Mat2 e;
	e.e_00 = m.e_11 * x;
	e.e_10 = -1 * m.e_10 * x;
	e.e_01 = -1 * m.e_01 * x;
	e.e_11 = m.e_00 * x;
	return e;
	}
	



Mat2 transpose( Mat2 const& m){
	Mat2 e = m;
	e.e_10 = m.e_01;
	e.e_01 = m.e_10;
	return e;
	}


Vec2 operator*(Mat2 const& m , Vec2 const& v){  
	Vec2 e;
	e.x = m.e_00 * v.x + m.e_10 * v.y;
	e.y = m.e_01 * v.x + m.e_11 * v.y;
	return e;
	}
Vec2 operator*(Vec2 const& v, Mat2 const& m){
	Vec2 e;
	e.x = m.e_00 * v.x + m.e_10 * v.y;
	e.y = m.e_01 * v.x + m.e_11 * v.y;
	return e;
	}

Mat2& Mat2::operator*=(Mat2 const& m ){
	
	float a = e_00 * m.e_00 + e_10 * m.e_01;
	float b = e_00 * m.e_10 + e_10 * m.e_11;
	float c = e_01 * m.e_00 + e_11 * m.e_01;
	float d = e_01 * m.e_10 + e_11 * m.e_11;

	e_00 = a;
	e_10 = b;
	e_01 = c;
	e_11 = d;

	return *this;
	}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
	Mat2 e;
	e.e_00 = m1.e_00 * m2.e_00 + m1.e_10 * m2.e_01;
	e.e_10 = m1.e_00 * m2.e_10 + m1.e_10 * m2.e_11;
	e.e_01 = m1.e_01 * m2.e_00 + m1.e_11 * m2.e_01;
	e.e_11 = m1.e_01 * m2.e_10 + m1.e_11 * m2.e_11;
	return e;
	}

float Mat2::det()const{
	float x = (e_11 * e_00 - e_10 * e_01);
		return x;
}