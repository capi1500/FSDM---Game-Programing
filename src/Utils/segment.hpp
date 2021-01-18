//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_SEGMENT_HPP
#define PROGRAMOWANIEGIER_SEGMENT_HPP

#include "line.hpp"

class Segment : public Line{
	private:
		sf::Vector2f p1;
		sf::Vector2f p2;
	public:
		bool pointInside(const sf::Vector2f point) const override;
		bool isCrossLine(const Line& line) const override;
		
		Segment(const sf::Vector2f& p1, const sf::Vector2f& p2);
};

#endif //PROGRAMOWANIEGIER_SEGMENT_HPP
