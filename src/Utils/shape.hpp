//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_SHAPE_HPP
#define PROGRAMOWANIEGIER_SHAPE_HPP

#include <SFML/System/Vector2.hpp>
#include <vector>

const float eps = 0.00001;

class Line;

class Shape{
	public:
		virtual bool pointInside(const sf::Vector2f point) const = 0;
		virtual bool isCrossLine(const Line& line) const = 0;
		virtual std::vector<sf::Vector2f> crossLine(const Line& line) const = 0;
		virtual void move(const sf::Vector2f& shift);
};

#endif //PROGRAMOWANIEGIER_SHAPE_HPP
