//
// Created by Kacper on 11/12/2020.
//

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

std::vector<sf::Vector2f> Circle::crossLine(const Line& line) const{

}
