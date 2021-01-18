//
// Created by Kacper on 11/12/2020.
//

#include "rectangle.hpp"

Rectangle::Rectangle(const sf::FloatRect& rect) : 	rect(rect),
													p1(rect.left, rect.top),
													p2(rect.left + rect.width, rect.top),
													p3(rect.left, rect.top + rect.height),
													p4(rect.left + rect.width, rect.top + rect.height),
													s1(p1, p2),
													s2(p2, p3),
													s3(p3, p4),
													s4(p4, p1){
}

bool Rectangle::pointInside(const sf::Vector2f point) const{
	return rect.contains(point);
}

bool Rectangle::isCrossLine(const Line& line) const{
	return s1.isCrossLine(line) && s2.isCrossLine(line) && s3.isCrossLine(line) && s4.isCrossLine(line);
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
	s2 = Segment(p2, p3);
	s3 = Segment(p3, p4);
	s4 = Segment(p4, p1);
}

void Rectangle::move(const sf::Vector2f& shift){
	rect.left += shift.x;
	rect.top += shift.y;
	update();
}

std::vector<sf::Vector2f> Rectangle::crossLine(const Line& line) const{
	std::vector<sf::Vector2f> out;
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
