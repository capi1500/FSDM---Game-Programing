//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_RECTANGLE_HPP
#define PROGRAMOWANIEGIER_RECTANGLE_HPP

#include <SFML/Graphics/Rect.hpp>
#include "shape.hpp"
#include "line.hpp"
#include "segment.hpp"

class Rectangle : public Shape{
	protected:
		sf::FloatRect rect;
		sf::Vector2f p1;
		sf::Vector2f p2;
		sf::Vector2f p3;
		sf::Vector2f p4;
		Segment s1;
		Segment s2;
		Segment s3;
		Segment s4;
		
		void update();
	public:
		bool pointInside(const sf::Vector2f point) const override;
		bool isCrossLine(const Line& line) const override;
		
		std::vector<std::pair<sf::Vector2f, Line>> crossLine(const Line& line) const override;
		
		void setRect(const sf::FloatRect& rect);
		
		void move(const sf::Vector2f& shift);
		
		Rectangle(const sf::FloatRect& rect);
		
		void print() const override;
};

#endif //PROGRAMOWANIEGIER_RECTANGLE_HPP
