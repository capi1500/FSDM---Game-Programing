//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_BALL_HPP
#define PROGRAMOWANIEGIER_BALL_HPP

#include "object.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Ball : public Object{
	private:
		sf::CircleShape m_circle;
		float m_velocity;
		float m_angle;
		sf::Vector2f m_oldPosition;
	public:
		void draw(sf::RenderWindow& window) override;
		void update(const sf::Time& time) override;
		void input(const sf::Event& input) override;
		
		void bounce();
		
		Ball(sf::Vector2u windowSize);
};

#endif //PROGRAMOWANIEGIER_BALL_HPP
