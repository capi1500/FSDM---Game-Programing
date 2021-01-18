//
// Created by Kacper on 11/12/2020.
//

#include <algorithm>
#include "segment.hpp"

bool Segment::pointInside(const sf::Vector2f point) const{
	return std::min(p1.x, p2.x) <= point.x and point.x <= std::max(p1.x, p2.x) and std::min(p1.y, p2.y) <= point.y and point.y <= std::max(p1.y, p2.y);
}

bool Segment::isCrossLine(const Line& line) const{
	return Line::isCrossLine(line) and pointInside(Line::crossLine(line)[0].first);
}

Segment::Segment(const sf::Vector2f& p1, const sf::Vector2f& p2) : Line(p1, p2), p1(p1), p2(p2){
}
