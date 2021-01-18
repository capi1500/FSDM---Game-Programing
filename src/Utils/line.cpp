//
// Created by Kacper on 11/12/2020.
//

#include <cmath>
#include "line.hpp"

bool Line::pointInside(const sf::Vector2f point) const{
	return abs(A * point.x + B * point.y + C) < eps;
}

std::vector<sf::Vector2f> Line::crossLine(const Line& line) const{
	const long double& A2 = line.getA();
	const long double& B2 = line.getB();
	const long double& C2 = line.getC();
	
	long double W = A * B2 - A2 * B;
	long double Wx = (-C) * B2 - (-C2) * B;
	long double Wy = A * (-C2) - A2 * (-C);
	
	if(W == 0) // równoległe
		return {};
	return {{static_cast<float>(Wx / W), static_cast<float>(Wy / W)}};
}

bool Line::isCrossLine(const Line& line) const{
	return A * B != line.getA() * line.getB();
}

Line Line::perpendicular(const sf::Vector2f& point) const{
	return Line(-B, A, B * point.x - A * point.y);
}

long double Line::distance(const sf::Vector2f& point) const{
	return abs(A * point.x + B * point.y + C) / sqrt(A * A + B * B);
}

long double Line::getA() const{
	return A;
}

long double Line::getB() const{
	return B;
}

long double Line::getC() const{
	return C;
}

Line::Line(long double a, long double b, long double c) : A(a), B(b), C(c){
}

Line::Line(const sf::Vector2f& p1, const sf::Vector2f& p2){
	A = p1.y - p2.y;
	B = p2.x - p1.x;
	C = p1.x * (p2.y - p1.y) - p1.y * (p2.x - p1.x);
}

Line::Line(){}