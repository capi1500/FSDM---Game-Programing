//
// Created by Kacper on 11/12/2020.
//

#include <cmath>
#include <iostream>
#include "ball.hpp"

void Ball::draw(sf::RenderWindow& window){
	window.draw(m_circle);
}

void Ball::update(const sf::Time& time){
	m_oldPosition = {m_circle.getPosition().x - m_circle.getRadius(), m_circle.getPosition().y - m_circle.getRadius()};
	m_circle.move(m_velocity * cos(m_angle) * time.asSeconds(), m_velocity * sin(m_angle) * time.asSeconds());
}

void Ball::input(const sf::Event& input){

}

void Ball::bounce(){
}

Ball::Ball(sf::Vector2u windowSize){
	m_circle.setRadius(50);
	m_circle.setPosition(-50 + windowSize.x / 2, -50 + windowSize.y / 2);
	m_velocity = 50;
	m_angle = (rand() % 360);
	std::cout << m_angle;
}


/*
 *
 * rand() - 0, 2000000000
 *
 * 2 * M_PI = 6.283...
 *
 */
