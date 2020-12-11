//
// Created by Kacper on 11/12/2020.
//

#include "paddle.hpp"

void Paddle::draw(sf::RenderWindow& window){
	window.draw(m_rect);
}

void Paddle::update(const sf::Time& time){
	if(sf::Keyboard::isKeyPressed(m_up)){
		m_rect.move(0, -m_velocity * time.asSeconds());
	}
	if(sf::Keyboard::isKeyPressed(m_down)){
		m_rect.move(0, m_velocity * time.asSeconds());
	}
}

void Paddle::input(const sf::Event& input){

}

const sf::FloatRect Paddle::getRect() const{
	return m_rect.getGlobalBounds();
}

Paddle::Paddle(sf::Keyboard::Key up, sf::Keyboard::Key down, int posx, int posy, int sizex, int sizey) : m_up(up), m_down(down){
	m_rect.setSize(sf::Vector2f(sizex, sizey));
	m_rect.setPosition(posx, posy);
	m_velocity = 50;
}
