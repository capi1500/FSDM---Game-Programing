//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_BUTTON_HPP
#define PROGRAMOWANIEGIER_BUTTON_HPP

#include <functional>
#include <SFML/Graphics/Text.hpp>
#include "object.hpp"

class Button : public Object{
	private:
		std::function<void()> m_function;
		sf::Text m_text;
		enum State{
			Default,
			Hover,
			Clicked
		};
		State m_state;
		sf::Time m_time;
	public:
		void draw(sf::RenderWindow& window) override;
		void update(const sf::Time& time) override;
		void input(const sf::Event& input) override;
		void restart() override;
		
		Button(std::function<void()> f, const sf::Vector2f& position, const std::string& label = "");
};

#endif //PROGRAMOWANIEGIER_BUTTON_HPP
