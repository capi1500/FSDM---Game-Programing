//
// Created by Kacper on 11/12/2020.
//

#include <cmath>
#include "vector.hpp"

Vector::Vector(long double x, long double y) : x(x), y(y){
}

Vector::Vector(const sf::Vector2f& a, const sf::Vector2f& b){
	x = b.x - a.x;
	y = b.y - a.y;
}

Vector::Vector(){
}

long double Vector::operator *(const Vector& u) const{
	return x * u.y - u.x * y;
}

long double Vector::operator ^(const Vector& u) const{
	return x * u.x + y * u.y;
}

Vector Vector::operator *(const long double r) const{
	return Vector(x * r, y * r);
}

Vector Vector::operator +(const Vector& u) const{
	return Vector(x + u.x, y + u.y);
}

Vector Vector::operator -(const Vector& u) const{
	return Vector(x - u.x, y - u.y);
}

Vector Vector::operator -() const{
	return Vector(-x, -y);
}

Vector& Vector::operator *=(const long double r){
	return (*this) = (*this) * r;
}

Vector& Vector::operator +=(const Vector& u){
	return (*this) = (*this) + u;
}

Vector& Vector::operator -=(const Vector& u){
	return (*this) = (*this) - u;
}

Vector Vector::normal() const{
	long double l = length();
	return Vector(x / l, y / l);
}

Vector& Vector::normalize(){
	return (*this) = normal();
}

long double Vector::length() const{
	return sqrt(x * x + y * y);
}

sf::Vector2f Vector::toVector2f() const{
	return sf::Vector2f(x, y);
}

Vector::Vector(sf::Vector2f v) : x(v.x), y(v.y){
}
