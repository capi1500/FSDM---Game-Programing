//
// Created by Kacper on 11/12/2020.
//

#include <cmath>
#include <iostream>
#include <Utils/vector.hpp>
#include "ball.hpp"

void Ball::draw(sf::RenderWindow& window){
	window.draw(m_circle);
}

void Ball::update(const sf::Time& time){
	m_oldPosition = {getPosition().x, getPosition().y};
	m_circle.move(m_velocity * cos(m_angle) * time.asSeconds(), m_velocity * sin(m_angle) * time.asSeconds());
}

void Ball::input(const sf::Event& input){

}

void Ball::bounce(const Line& line){
	sf::Vector2f o = getOldPosition(), n = getPosition(), np, c = line.crossLine(Line(o, n))[0].first;
	
	Vector u = Vector(c, n), dir;
	if(line.getB() == 0)
		dir = Vector(0, -line.getC() / line.getA());
	else
		dir = Vector(-line.getC() / line.getB(), 0);
	dir.normalize();
	long double r = dir ^ u;
	dir *= r;
	Vector shift = -u + dir;
	np = (Vector(n) + shift * 2).toVector2f();
	
	m_oldPosition = c;
	setCenter(np);
	
	u = Vector(c, np);
	m_angle = atan2(u.y, u.x);
}

Ball::Ball(sf::Vector2u windowSize){
	m_circle.setRadius(50);
	setCenter({windowSize.x / 2.f, windowSize.y / 2.f});
	m_velocity = 50;
	m_angle = (rand() % static_cast<int>(2 * M_PI * 1000)) / 1000.0;
}

void Ball::setCenter(const sf::Vector2f& p){
	m_circle.setPosition(p.x - getRadius(), p.y - getRadius());
}

sf::Vector2f Ball::getPosition() const{
	return m_circle.getPosition() + sf::Vector2f(getRadius(), getRadius());
}

const sf::Vector2f& Ball::getOldPosition() const{
	return m_oldPosition;
}

float Ball::getRadius() const{
	return m_circle.getRadius();
}