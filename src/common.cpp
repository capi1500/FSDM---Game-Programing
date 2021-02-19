//
// Created by capi1500 on 20.01.2021.
//

#include <SFML/System.hpp>
#include <cmath>
#include <Signal/signal.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "soundBoard.hpp"
#include <FiniteStateMachine/finiteStateMachine.hpp>

double distance(const sf::Vector2f& a, const sf::Vector2f& b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int windowSizeY, windowSizeX;
SoundBoard soundBoard;
sf::RenderWindow window;
FiniteStateMachine machine;
Signal eventQueue;
sf::Font font;
sf::SoundBuffer clickSound, unclickSound, hoverSound;