//
// Created by Kacper on 04/12/2020.
//

#ifndef PROGRAMOWANIEGIER_OBJECT_HPP
#define PROGRAMOWANIEGIER_OBJECT_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Object{
	public:
		virtual void draw(sf::RenderWindow& window) = 0;
		virtual void update(const sf::Time& time) = 0;
		virtual void input(const sf::Event& input) = 0;
		
		virtual ~Object() = default;
};

#endif //PROGRAMOWANIEGIER_OBJECT_HPP
