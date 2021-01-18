//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_LINE_HPP
#define PROGRAMOWANIEGIER_LINE_HPP

#include "shape.hpp"

class Line : public Shape{
	protected:
		long double A;
		long double B;
		long double C;
	public:
		bool pointInside(const sf::Vector2f point) const override;
		std::vector<sf::Vector2f> crossLine(const Line& line) const override;
		bool isCrossLine(const Line& line) const override;
		Line perpendicular(const sf::Vector2f& point) const;
		long double distance(const sf::Vector2f& point) const;
		
		long double getA() const;
		long double getB() const;
		long double getC() const;
		
		Line(long double a, long double b, long double c);
		Line(const sf::Vector2f& p1, const sf::Vector2f& p2);
		Line();
};

#endif //PROGRAMOWANIEGIER_LINE_HPP
