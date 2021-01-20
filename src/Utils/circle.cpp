//
// Created by Kacper on 11/12/2020.
//

#include <cmath>
#include <iostream>
#include "circle.hpp"
#include "line.hpp"

bool Circle::pointInside(const sf::Vector2f point) const{
	return (point.x - center.x) * (point.x - center.x) + (point.y - center.y) * (point.y - center.y) <= (radious + eps) * (radious + eps);
}

bool Circle::isCrossLine(const Line& line) const{
	return line.distance(center) <= radious + eps;
}

long double Circle::getRadious() const{
	return radious;
}

const sf::Vector2f& Circle::getCenter() const{
	return center;
}

Circle::Circle(long double radious, const sf::Vector2f& center) : radious(radious), center(center){
}

void Circle::move(const sf::Vector2f& shift){
	center += shift;
}

std::vector<std::pair<sf::Vector2f, Line>> Circle::crossLine(const Line& line) const{
	long double a = line.getA(), b = line.getB(), c = line.getC(), p = getCenter().x, q = getCenter().y, r = getRadious();
	long double x1, y1, x2, y2;
	if(b == 0){
		x1 = x2 = -c / a;
		int d = sqrt(a*a*r*r - (a*p + c) * (a*p + c));
		x1 = q + d;
		x2 = q - d;
	}
	else{
		long double bb = b * b;
		long double t1 = 1 + a*a/bb;
		long double t2 = 2*a*c/bb + 2*q*a/b - 2*p;
		long double t3 = p*p + q*q - r*r + c*c/bb + 2*q*c/b;
		long double d = sqrt(t2*t2 - 4*t1*t3);
		x1 = (-t2 + d) / (2 * t1);
		x2 = (-t2 - d) / (2 * t1);
		y1 = (-c - a*x1) / b;
		y2 = (-c - a*x2) / b;
	}
	sf::Vector2f p1 = sf::Vector2f(x1, y1);
	sf::Vector2f p2 = sf::Vector2f(x2, y2);
	
	return {{p1, tangent(p1)}, {p2, tangent(p2)}};
}

Line Circle::tangent(sf::Vector2f point) const{
	return Line(center, point).perpendicular(point);
}

void Circle::print() const{
	std::cout << "(x - " << center.x << ")^2 + (y - " << center.y << ")^2 =" << radious << "^2";
}
