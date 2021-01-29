//
// Created by Kacper on 15/01/2021.
//

#ifndef PROGRAMOWANIEGIER_COMMON_HPP
#define PROGRAMOWANIEGIER_COMMON_HPP

#include <cmath>
#include <SFML/System.hpp>
#include <Signal/signal.hpp>
#include <SFML/Graphics/Font.hpp>

const float radious = 40;
extern int windowSizeY, windowSizeX;
extern Signal eventQueue;
extern sf::Font font;
double distance(const sf::Vector2f& a, const sf::Vector2f& b);

#endif //PROGRAMOWANIEGIER_COMMON_HPP
