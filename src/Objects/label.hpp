//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_LABEL_HPP
#define PROGRAMOWANIEGIER_LABEL_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "object.hpp"

class Label : public Object{
	private:
		sf::Text m_text;
	public:
		void draw(sf::RenderWindow& window) override;
		void update(const sf::Time& time) override;
		void input(const sf::Event& input) override;
		void restart() override;
		
		Label(const sf::Vector2f& position, const std::string& label, unsigned size = 30);
};

#endif //PROGRAMOWANIEGIER_LABEL_HPP
