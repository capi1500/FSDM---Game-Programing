//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_PADDLE_HPP
#define PROGRAMOWANIEGIER_PADDLE_HPP

#include "object.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class Paddle : public Object{
	private:
		sf::RectangleShape m_rect;
		sf::Keyboard::Key m_up;
		sf::Keyboard::Key m_down;
		float m_velocity;
	public:
		void draw(sf::RenderWindow& window) override;
		void update(const sf::Time& time) override;
		void input(const sf::Event& input) override;
		
		const sf::FloatRect getRect() const;
		
		Paddle(sf::Keyboard::Key up, sf::Keyboard::Key down, int posx, int posy, int sizex, int sizey);
};

#endif //PROGRAMOWANIEGIER_PADDLE_HPP
