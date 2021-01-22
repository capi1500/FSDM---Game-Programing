//
// Created by capi1500 on 20.01.2021.
//

#include <SFML/System.hpp>
#include <cmath>

double distance(const sf::Vector2f& a, const sf::Vector2f& b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}