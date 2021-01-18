//
// Created by Kacper on 15/01/2021.
//

#ifndef PROGRAMOWANIEGIER_COMMON_HPP
#define PROGRAMOWANIEGIER_COMMON_HPP

#include <cmath>

const float radious = 50;

double distance(const sf::Vector2f& a, const sf::Vector2f& b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

#endif //PROGRAMOWANIEGIER_COMMON_HPP
