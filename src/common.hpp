//
// Created by Kacper on 15/01/2021.
//

#ifndef PROGRAMOWANIEGIER_COMMON_HPP
#define PROGRAMOWANIEGIER_COMMON_HPP

#include <cmath>
#include <SFML/System.hpp>
#include <Signal/signal.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <FiniteStateMachine/finiteStateMachine.hpp>
#include "soundBoard.hpp"

const float radious = 40;
extern int windowSizeY, windowSizeX;
extern Signal eventQueue;
extern SoundBoard soundBoard;
extern sf::RenderWindow window;
extern FiniteStateMachine machine;
extern sf::Font font;
extern sf::SoundBuffer clickSound, unclickSound, hoverSound, bounceSound;
double distance(const sf::Vector2f& a, const sf::Vector2f& b);

#endif //PROGRAMOWANIEGIER_COMMON_HPP
