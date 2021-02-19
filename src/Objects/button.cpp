//
// Created by Kacper on 11/12/2020.
//

#include <common.hpp>
#include <SFML/Audio/Sound.hpp>
#include "button.hpp"

void Button::draw(sf::RenderWindow& window){
	window.draw(m_text);
}

void Button::update(const sf::Time& time){
	if(m_state == Clicked){
		m_time += time;
		if(m_time > sf::milliseconds(500)){
			soundBoard.play(unclickSound);
			m_state = Default;
			m_text.setFillColor(sf::Color::White);
		}
	}
	sf::Vector2i pos = sf::Mouse::getPosition();
	if(m_text.getGlobalBounds().contains(pos.x, pos.y)){
		if(m_state == Default){
			m_text.setFillColor(sf::Color(127, 127, 127));
			soundBoard.play(hoverSound);
			m_state = Hover;
		}
	}
	else{
		if(m_state == Hover){
			m_text.setFillColor(sf::Color::White);
			soundBoard.play(hoverSound);
			m_state = Default;
		}
	}
}

void Button::input(const sf::Event& input){
	if(m_state == Hover){
		if(input.type == sf::Event::MouseButtonPressed){
			if(input.mouseButton.button == sf::Mouse::Left){
				if(m_text.getGlobalBounds().contains(input.mouseButton.x, input.mouseButton.y)){
					soundBoard.play(clickSound);
					m_function();
					m_state = Clicked;
					m_time = sf::milliseconds(0);
					m_text.setFillColor(sf::Color(63, 63, 63));
				}
			}
		}
	}
}

void Button::restart(){

}

Button::Button(std::function<void()> f, const sf::Vector2f& position, const std::string& label) : m_function(f){
	m_text.setFont(font);
	m_text.setString(label);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(30);
	m_text.setPosition(position.x - m_text.getLocalBounds().width / 2, position.y - m_text.getLocalBounds().height / 2);
	startPosition = position;
	m_state = Default;
}