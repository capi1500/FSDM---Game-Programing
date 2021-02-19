//
// Created by Kacper on 11/12/2020.
//

#include <common.hpp>
#include "label.hpp"

void Label::draw(sf::RenderWindow& window){
	window.draw(m_text);
}

void Label::update(const sf::Time& time){

}

void Label::input(const sf::Event& input){

}

void Label::restart(){

}

Label::Label(const sf::Vector2f& position, const std::string& label, unsigned size){
	m_text.setFont(font);
	m_text.setString(label);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(size);
	m_text.setPosition(position.x - m_text.getLocalBounds().width / 2, position.y - m_text.getLocalBounds().height / 2);
	startPosition = position;
}
