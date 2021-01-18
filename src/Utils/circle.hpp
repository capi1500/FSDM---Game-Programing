//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_CIRCLE_HPP
#define PROGRAMOWANIEGIER_CIRCLE_HPP

#include <utility>
#include "shape.hpp"

class Circle : public Shape{
	private:
		long double radious;
		sf::Vector2f center;
	public:
		bool pointInside(const sf::Vector2f point) const override;
		bool isCrossLine(const Line& line) const override;
		void move(const sf::Vector2f& shift) override;
		
		std::vector<std::pair<sf::Vector2f, Line>> crossLine(const Line& line) const override;
		
		Line tangent(const sf::Vector2f point) const;
		
		long double getRadious() const;
		const sf::Vector2f& getCenter() const;
		
		Circle(long double radious, const sf::Vector2f& center);
		
		void print() const override;
};

#endif //PROGRAMOWANIEGIER_CIRCLE_HPP
