#include "vec2.hpp"



Vec2& Vec2::operator+=(Vec2 const& v){
	x = x + v.x;
	y = y + v.y;
	return *this;
	}

Vec2& Vec2::operator-=(Vec2 const& v){
	x = x - v.x;
	y = y - v.y;
	return *this;
	}

Vec2& Vec2::operator*=(float s){
	x = x * s;
	y = y * s;
	return *this;
	}

Vec2& Vec2::operator/=(float s){
	x = x / s;
	y = y / s;
	return *this;
	}

Vec2 operator+(Vec2 const& u ,Vec2 const& v){
	Vec2 e;
	e.x = u.x + v.x;
	e.y = u.y + v.y;
	return e;
	}

Vec2 operator-(Vec2 const& u ,Vec2 const& v){
	Vec2 e;
	e.x = u.x - v.x;
	e.y = u.y - v.y;
	return e;
	}

Vec2 operator *( Vec2 const& v , float s ){
	Vec2 e;
	e.x = v.x * s;
	e.y = v.y * s;
	return e;
	}

Vec2 operator /( Vec2 const& v , float s ){
	Vec2 e;
	e.x = v.x / s;
	e.y = v.y / s;
	return e;
	}

Vec2 operator *( float s  , Vec2 const& v){
	Vec2 e;
	e.x = v.x * s;
	e.y = v.y * s;
	return e;
	}
