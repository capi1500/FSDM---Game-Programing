//
// Created by Kacper on 11/12/2020.
//

#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle(const sf::FloatRect& rect) : 	rect(rect),
													p1(rect.left, rect.top),
													p2(rect.left + rect.width, rect.top),
													p3(rect.left, rect.top + rect.height),
													p4(rect.left + rect.width, rect.top + rect.height),
													s1(p1, p2),
													s2(p2, p4),
													s3(p4, p3),
													s4(p3, p1){
}

bool Rectangle::pointInside(const sf::Vector2f point) const{
	float x1 = rect.left, x2 = rect.left + rect.width;
	float y1 = rect.top, y2 = rect.top + rect.height;
	return x1 - eps <= point.x and point.x <= x2 + eps and y1 - eps <= point.y and point.y <= y2 + eps;
}

bool Rectangle::isCrossLine(const Line& line) const{
	return s1.isCrossLine(line) || s2.isCrossLine(line) || s3.isCrossLine(line) || s4.isCrossLine(line);
}

void Rectangle::setRect(const sf::FloatRect& rect){
	Rectangle::rect = rect;
	update();
}

void Rectangle::update(){
	p1 = sf::Vector2f(rect.left, rect.top);
	p2 = sf::Vector2f(rect.left + rect.width, rect.top);
	p3 = sf::Vector2f(rect.left, rect.top + rect.height);
	p4 = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
	s1 = Segment(p1, p2);
	s2 = Segment(p2, p4);
	s3 = Segment(p4, p3);
	s4 = Segment(p3, p1);
}

void Rectangle::move(const sf::Vector2f& shift){
	rect.left += shift.x;
	rect.top += shift.y;
	update();
}

std::vector<std::pair<sf::Vector2f, Line>> Rectangle::crossLine(const Line& line) const{
	std::vector<std::pair<sf::Vector2f, Line>> out;
	if(s1.isCrossLine(line))
		out.push_back(s1.crossLine(line)[0]);
	if(s2.isCrossLine(line))
		out.push_back(s2.crossLine(line)[0]);
	if(s3.isCrossLine(line))
		out.push_back(s3.crossLine(line)[0]);
	if(s4.isCrossLine(line))
		out.push_back(s4.crossLine(line)[0]);
	return out;
}

void Rectangle::print() const{
	std::cout << "{" << rect.left << ", " << rect.top << "}, {" << rect.left + rect.width << ", " << rect.top + rect.height << "}";
}
