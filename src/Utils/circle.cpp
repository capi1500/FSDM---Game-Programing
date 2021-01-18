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
	long double x1, y1, x2, y2, d;
	if(b == 0){
		x1 = x2 = -c / a;
		d = sqrt(a*a*r*r - (a*p + c) * (a*p + c));
		x1 = q + d;
		x2 = q - d;
	}
	else{
		d = sqrt(2 * (a*a*c*c + a*a*b*b*q*q - 4*a*b*b*c*p - 4*a*b*b*b*p*q + 2*a*a*b*c*q + 8*b*b*b*b*r*r - 2*b*b*c*c - 2*b*b*b*q*q - 4*b*b*b*c*q - 2*a*a*b*b*r*r + 2*a*a*b*b*p*p));
		x1 = (4*b*b*p - a*b*q - a*c + d) / (4*b*b - a*a);
		x2 = (4*b*b*p - a*b*q - a*c - d) / (4*b*b - a*a);
		y1 = (-c - a*x1) / b;
		y2 = (-c - a*x2) / b;
	}
	sf::Vector2f p1 = sf::Vector2f(x1, y1);
	sf::Vector2f p2 = sf::Vector2f(x2, y2);
	
	/// DEBUG
	auto printVec = [] (const sf::Vector2f& v) {
		std::cout << "{" << v.x << ", " << v.y << "}";
	};
	
	std::cout << "Cross circle ";
	print();
	std::cout << " and line ";
	line.print();
	std::cout << " ";
	printVec(p1);
	std::cout << " ";
	printVec(p2);
	std::cout << "\n";
	
	/// END DEBUG
	
	return {{p1, tangent(p1)}, {p2, tangent(p2)}};
}

Line Circle::tangent(sf::Vector2f point) const{
	return Line(center, point).perpendicular(point);
}

void Circle::print() const{
	std::cout << "(x - " << center.x << ")^2 + (y - " << center.y << ")^2 =" << radious << "^2";
}
